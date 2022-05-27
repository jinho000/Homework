#pragma once
#include <GameServerBase/ServerBaseObject.h>
#include "IPEndPoint.h"
#include "GameServerBase/ServerQueue.h"

// ���������� ����� Ŭ���̾�Ʈ ������ ó���ϴ� Ŭ����
// ������ �̸� �����ΰ� Ŭ���̾�Ʈ�� ������ ��ٸ���
// Ŭ���̾�Ʈ�� ������ ���� ���ǰ� �����Ų��
// Ŭ��Ϳ���� ������������ ������ ��ε�ĳ������ ó���Ѵ�
class ServerQueue;
class TCPSession;
class TCPListener : public ServerBaseObject
{
	friend class TCPSession;
	static UINT listenThreadCount;

private: // member var
	SOCKET												m_listenerSocket;
	IPEndPoint											m_ipEndPoint;
	const ServerQueue*									m_pNetQueue;
	std::function<void(std::shared_ptr<TCPSession>)>	m_acceptCallback; // Ŭ���̾�Ʈ���� �Ϸ� �� ȣ��� �Լ�
	std::function<void(BOOL, DWORD, LPOVERLAPPED)>		m_listenCallback; // Ŭ���̾�Ʈ�� ���������� ȣ��Ǵ� �Լ�
	
	std::vector<std::shared_ptr<TCPSession>>			m_sessionPool;	  // ��ü ������ ���� Ǯ
	std::deque<std::shared_ptr<TCPSession>>				m_acceptPool;
	std::mutex											m_acceptPoolLock;

	std::unordered_map<__int64, std::shared_ptr<TCPSession>>	m_connectionPool;
	std::mutex													m_connectionPoolLock;

public: // default
	TCPListener();
	~TCPListener();

	TCPListener(const TCPListener& _other) = delete;
	TCPListener(TCPListener&& _other) = delete;
	TCPListener& operator=(const TCPListener& _other) = delete;
	TCPListener& operator=(const TCPListener&& _other) = delete;

private:
	void CloseSocket(); // listen ���� ����

	// session�� ����� accept�Լ� ����
	// ��Ȱ���� ������ �ִ°�� ��Ȱ���� ���� ���
	void CreateAcceptSession();

	// Ŭ���̾�Ʈ ���� ��û �̺�Ʈ �߻��� ȣ���Լ�
	void OnAccept(BOOL _result, DWORD _byteSize, LPOVERLAPPED _overlapped);

	// Ŭ�� ���ӵ� ���� �����ϱ�
	void CloseSession(PtrSTCPSession _tcpSession);

public: // member Func
	void Initialize(const std::string _ip, int _port, const std::function<void(std::shared_ptr<TCPSession>)>& _acceptCallback);
	void StartAccept(UINT _backLog);

	void BindNetQueue(const ServerQueue& _workQueue);

	void BroadCast(const std::vector<uint8_t>& _buffer, PtrSTCPSession _exceptSession);
	void BroadCast(const std::vector<uint8_t>& _buffer);

};

