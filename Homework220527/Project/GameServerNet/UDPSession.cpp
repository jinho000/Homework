#include "pch.h"
#include "UDPSession.h"
#include <GameServerBase/ServerDebug.h>
#include "SocketAddress.h"
#include "Overlapped.h"
#include "UDPRecvOverlapped.h"

UDPSession::UDPSession(const IPEndPoint& _ipEndPoint)
	: m_sessionSocket(NULL)
	, m_localAddr(_ipEndPoint)
	, m_recvOveralpped(nullptr)
	, m_remoteAddr({})

	, flag(0)
	, addrSize(0)
{
	m_sessionSocket = WSASocket(AF_INET, SOCK_DGRAM, IPPROTO::IPPROTO_UDP, NULL, NULL, WSA_FLAG_OVERLAPPED);

	if (INVALID_SOCKET == m_sessionSocket)
	{
		ServerDebug::LogError("UDP Socket Error");
		ServerDebug::GetLastErrorPrint();
	}

	// UDP���� �ּҰ� ����
	SocketAddress socketAddress = m_localAddr.Serialize();
	int Error = bind(m_sessionSocket, reinterpret_cast<const sockaddr*>(socketAddress.GetBuffer()), static_cast<int>(socketAddress.GetBufferLength()));

	if (Error == SOCKET_ERROR)
	{
		ServerDebug::LogError("UDP Socket Bind Error");
		ServerDebug::GetLastErrorPrint();
	}

	m_UDPIOCallback = std::bind(&UDPSession::OnIOCallBack, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);

	// recvOverlapped 
	m_recvOveralpped = new UDPRecvOverlapped(this);

	// recvfrom error
	//memset(&m_remoteAddr, 0x00, sizeof(m_remoteAddr));
	//addrSize = static_cast<int>(sizeof(m_remoteAddr));
	memset(&m_remoteAddr, 0x00, sizeof(m_remoteAddr));
	addrSize = static_cast<int>(sizeof(m_remoteAddr));

	// send pool �ʱ�ȭ
	for (int i = 0; i < 20; ++i)
	{
		m_sendPool.push(new UDPSendOverlapped(this));
	}
}

UDPSession::~UDPSession()
{
	delete m_recvOveralpped;
	m_recvOveralpped = nullptr;

	while (m_sendPool.empty() == false)
	{
		UDPSendOverlapped* pSendOverlapped = m_sendPool.front(); m_sendPool.pop();
		delete pSendOverlapped;
		pSendOverlapped = nullptr;
	}
}

void UDPSession::OnIOCallBack(BOOL _result, DWORD _numberOfBytes, LPOVERLAPPED _lpOverlapped)
{
	if (nullptr == _lpOverlapped)
	{
		return;
	}

	// �������� �ּҿ��� �������带 ���� ��ü ��������
	Overlapped* pOverlapped = reinterpret_cast<Overlapped*>(reinterpret_cast<char*>(_lpOverlapped) - sizeof(void*));
	pOverlapped->Excute(_result, _numberOfBytes);
}

bool UDPSession::BindQueue(const ServerQueue& _workQueue)
{
	return _workQueue.RegistSocket(m_sessionSocket, &m_UDPIOCallback);
}

void UDPSession::RequestRecv()
{
	// recv��û �� �޾ƿ� ������ �ֱ�
	// Ŭ���̾�Ʈ �����͸� ������ �Ű������� �־��� ������ ���� ���´�
	int Result = WSARecvFrom(m_sessionSocket, m_recvOveralpped->GetWSABuffer(), 1, m_recvOveralpped->GetBufferLength()
		, &flag, reinterpret_cast<sockaddr*>(&m_remoteAddr), &addrSize, m_recvOveralpped->GetLPOverlapped(), nullptr);

	if (SOCKET_ERROR == Result)
	{
		if (WSA_IO_PENDING != WSAGetLastError())
		{
			ServerDebug::GetLastErrorPrint();
			ServerDebug::AssertDebugMsg("WSARecvFrom Error");
		}
	}
}

void UDPSession::OnRecv(const char* _data, DWORD _byteSize)
{
	if (nullptr != m_recvCallBack)
	{
		// buffer�� ������ �ֱ�
		std::vector<unsigned char> Buffer;
		Buffer.resize(_byteSize);
		memcpy_s(&Buffer[0], Buffer.size(), _data, _byteSize);

		// ��û�� Ŭ���̾�Ʈ�� IPEndPoint�� ����� recvCallback ����
		IPEndPoint remoteEndPoint(m_remoteAddr.sin_addr.s_addr, htons(m_remoteAddr.sin_port));
		m_recvCallBack(DynamicCast<UDPSession>(), Buffer, remoteEndPoint);
	}
	else
	{
		ServerDebug::LogWarning("UDP recvCallBack is nullptr");
	}

	// recv ��û ó�� �� �ٽ� recv ��û
	RequestRecv();
}

void UDPSession::SetRecvCallBack(RecvCallBack _recvCallback)
{
	m_recvCallBack = _recvCallback;
}

void UDPSession::Send(const std::vector<unsigned char>& _buffer, const IPEndPoint& _userEndPoint)
{
	UDPSendOverlapped* sendOverlapped = nullptr;
	if (m_sendPool.empty())
	{
		sendOverlapped = new UDPSendOverlapped(this);
	}
	else
	{
		m_sendPoolMutex.lock();
		sendOverlapped = m_sendPool.front(); m_sendPool.pop();
		m_sendPoolMutex.unlock();
	}

	// ������ ���� �� ����
	sendOverlapped->CopyFrom(_buffer);
	SocketAddress sockaddress = _userEndPoint.Serialize();
	int Result = WSASendTo(m_sessionSocket, sendOverlapped->GetBuffer(), 1, sendOverlapped->GetBufferLength()
		, 0, reinterpret_cast<const sockaddr*>(sockaddress.GetBuffer()), static_cast<int>(sockaddress.GetBufferLength()), sendOverlapped->GetLPOverlapped(), nullptr);

	if (SOCKET_ERROR == Result)
	{
		if (WSA_IO_PENDING != WSAGetLastError())
		{
			ServerDebug::GetLastErrorPrint();			
		}
	}

}

void UDPSession::OnSendComplete(UDPSendOverlapped* _sendOverlapped)
{
	m_sendPoolMutex.lock();
	m_sendPool.push(_sendOverlapped);
	m_sendPoolMutex.unlock();
}
