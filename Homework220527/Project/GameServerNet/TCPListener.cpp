#include "pch.h"
#include "TCPListener.h"
#include "SocketAddress.h"
#include "ServerHelper.h"
#include "AcceptExOverlapped.h"
#include "TCPSession.h"
#include "GameServerBase/ServerDebug.h"

UINT TCPListener::listenThreadCount = 4;

TCPListener::TCPListener()
	: m_listenerSocket(NULL)
	, m_ipEndPoint()
	, m_pNetQueue(nullptr)
	, m_acceptCallback(nullptr)
	, m_listenCallback(std::bind(&TCPListener::OnAccept, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3))
{
}

TCPListener::~TCPListener()
{
}

void TCPListener::Initialize(const std::string _ip, int _port, const std::function<void(std::shared_ptr<TCPSession>)>& _acceptCallback)
{
	m_acceptCallback = _acceptCallback;
	m_ipEndPoint = IPEndPoint(_ip, _port);

	m_listenerSocket = WSASocket(AF_INET, SOCK_STREAM, IPPROTO::IPPROTO_TCP, NULL, NULL, WSA_FLAG_OVERLAPPED);
	if (INVALID_SOCKET == m_listenerSocket)
	{
		ServerDebug::LogError("WSASocket error");
		return;
	}


	SocketAddress addrSerial = (m_ipEndPoint.Serialize());
	int ErrorCode = ::bind(m_listenerSocket, reinterpret_cast<const sockaddr*>(addrSerial.GetBuffer()), (int)addrSerial.GetBufferLength());
	if (SOCKET_ERROR == ErrorCode)
	{
		CloseSocket();
		ServerDebug::LogError("bind error");
		ServerDebug::GetLastErrorPrint();
		return;
	}

	BOOL on = TRUE;
	ErrorCode = setsockopt(m_listenerSocket, SOL_SOCKET, SO_CONDITIONAL_ACCEPT, reinterpret_cast<const char*>(&on), sizeof(on));
	if (SOCKET_ERROR == ErrorCode)
	{
		CloseSocket();
		ServerDebug::LogError("socket opt error");
		return;
	}

	int backLog = 512;
	ErrorCode = listen(m_listenerSocket, backLog);
	if (SOCKET_ERROR == ErrorCode)
	{
		CloseSocket();
		ServerDebug::LogError("listen error");
		return;
	}
}

void TCPListener::StartAccept(UINT _backLog)
{
	if (128 < _backLog)
	{
		SYSTEM_INFO sysInfo;
		GetSystemInfo(&sysInfo);
		_backLog = sysInfo.dwNumberOfProcessors;
	}

	// backlog ������ŭ �̸� ������ ����� ����
	for (UINT i = 0; i < _backLog; i++)
	{
		CreateAcceptSession();
	}
}

void TCPListener::BindNetQueue(const ServerQueue& _workQueue)
{
	static bool once = false;
	if (once == true)
	{
		ServerDebug::AssertDebugMsg("Bind NetQueue twice");
		return;
	}
	once = true;


	// Bind queue
	// ������ ���ϰ� ������ �޾Ƶ��̴� �Լ� ����
	// �񵿱� ó��
	m_pNetQueue = &_workQueue;
	m_pNetQueue->RegistSocket(m_listenerSocket, &m_listenCallback);
}

void TCPListener::CreateAcceptSession()
{
	PtrSTCPSession newSession = nullptr;
	{
		m_acceptPoolLock.lock();

		if (m_acceptPool.empty())
		{
			newSession = std::make_shared<TCPSession>();
			newSession->Initialize();
			newSession->SetParent(this);
			m_sessionPool.push_back(newSession);
			
			std::string log = "Create ";
			log += std::to_string(static_cast<int>(newSession->GetSessionSocket()));
			log += " Socket";
			ServerDebug::LogInfo(log);
		}
		else
		{
			// Ŀ�ؼ� Ǯ�� ������ ������� ��Ȱ��
			newSession = m_acceptPool.front();
			m_acceptPool.pop_front();
			newSession->SetReuse();

			//std::string log = "Reuse ";
			//log += std::to_string(static_cast<int>(newSession->GetSessionSocket()));
			//log += " Socket";
			//ServerDebug::LogInfo(log);
		}

		m_acceptPoolLock.unlock();
	}

	// ���� �Ϸ� �� ������ overlapped
	AcceptExOverlapped* pAccetExOver = newSession->GetAcceptExOverlapped();

	// AcceptEx �Լ� ȣ��
	DWORD dwByte = 0;
	BOOL result = AcceptEx(m_listenerSocket
		, newSession->GetSessionSocket()
		, pAccetExOver->GetBuffer()
		, 0
		, sizeof(sockaddr_in) + 16
		, sizeof(sockaddr_in) + 16
		, &dwByte
		, pAccetExOver->GetLPOverlapped());

	if (FALSE == result)
	{
		if (ERROR_IO_PENDING != WSAGetLastError())
		{
			ServerDebug::LogInfo("AcceptEx Error");
			return;
		}
	}
}

void TCPListener::OnAccept(BOOL _result, DWORD _byteSize, LPOVERLAPPED _overlapped)
{
	ServerDebug::LogInfo("Client request connection");

	if (nullptr == _overlapped)
	{
		ServerDebug::LogWarning("OnAccept overlapped�� ����");
		return;
	}

	if (nullptr == m_acceptCallback)
	{
		ServerDebug::LogWarning("accept callback�� ����");
		return;
	}

	if (0 == _result)
	{
		ServerDebug::LogError("accept error");
		return;
	}

	// overlapped ��ü ��������
	AcceptExOverlapped* acceptExOver = reinterpret_cast<AcceptExOverlapped*>(reinterpret_cast<char*>(_overlapped) - sizeof(void*));

	// acceptExOver ��ü�� ����Ʈ, ���� �ּҰ��� ä������
	acceptExOver->Excute(_result, _byteSize);

	// Ŭ��� ����� ���ǿ� IOCP ������ ���ú� ��û
	std::shared_ptr<TCPSession> session = acceptExOver->GetTCPSession();
	session->BindQueue(*m_pNetQueue);
	session->RequestRecv();

	// ���� �����ϱ�
	m_connectionPoolLock.lock();
	m_connectionPool.insert(std::make_pair(session->GetSessionID(), session));

	m_connectionPoolLock.unlock();

	// callback �Լ� ����
	m_acceptCallback(session);


	// �����ڰ� ���� ������ ������
	// �������� �ϳ��� ����
	CreateAcceptSession();
}

void TCPListener::CloseSession(PtrSTCPSession _tcpSession)
{
	// session���� ó���� ����

	// ���� �ʿ��� ����
	{
		std::lock_guard<std::mutex> lock(m_connectionPoolLock);
		m_connectionPool.erase(_tcpSession->GetSessionID());
	}

	// ��Ȱ���ϱ� ���� connection Ǯ�� �߰�
	{
		std::lock_guard<std::mutex> lock(m_acceptPoolLock);
		m_acceptPool.push_back(_tcpSession);

		std::string log = "Reuse ";
		log += std::to_string(static_cast<int>(_tcpSession->GetSessionSocket()));
		log += " Socket";
		ServerDebug::LogInfo(log);
	}
}

void TCPListener::CloseSocket()
{
	if (NULL != m_listenerSocket)
	{
		closesocket(m_listenerSocket);
		m_listenerSocket = NULL;
	}
}

void TCPListener::BroadCast(const std::vector<uint8_t>& _buffer, PtrSTCPSession _exceptSession)
{
	ServerDebug::LogInfo("BroadCast");

	std::lock_guard<std::mutex> lockGuard(m_connectionPoolLock);

	auto iter = m_connectionPool.begin();
	while (iter != m_connectionPool.end())
	{
		// ��Ŷ��û�� ������ �����ϰ� �����ϴ� ���
		if (iter->second == _exceptSession)
		{
			++iter;
			continue;
		}
		iter->second->Send(_buffer);
		++iter;
	}
}

void TCPListener::BroadCast(const std::vector<uint8_t>& _buffer)
{
	BroadCast(_buffer, nullptr);
}
