#pragma once
#include "IPEndPoint.h"
#include <GameServerBase/ServerBaseObject.h>
#include <GameServerBase/ServerQueue.h>
#include "UDPSendOverlapped.h"

class UDPSession;
using RecvCallBack = std::function<void(std::shared_ptr<UDPSession>, const std::vector<unsigned char>&, IPEndPoint&)>;

// UDP����� ���� ����
class UDPRecvOverlapped;
class UDPSession : public ServerBaseObject
{
private: // member var
	IPEndPoint	m_localAddr;
	SOCKADDR_IN	m_remoteAddr;
	SOCKET		m_sessionSocket;

	using UDPIOCallback = std::function<void(BOOL, DWORD, LPOVERLAPPED)>;
	UDPIOCallback	m_UDPIOCallback; // ���Ǽ��� IO�̺�Ʈ �߻��� ȣ���Լ� �Լ���ü
	
	RecvCallBack	m_recvCallBack; // Ŭ���̾�Ʈ�� ���ú� ������ ó���Լ�

	// recvOverlapped ����ȭó��?
	UDPRecvOverlapped* m_recvOveralpped;

	// ���ÿ� send�� �ϱ����� ť�� sendpooló�� ���
	std::queue<UDPSendOverlapped*> m_sendPool;
	std::mutex m_sendPoolMutex;

	// WSARecvFrom err
	DWORD	flag;
	int		addrSize;

public: // default
	UDPSession(const IPEndPoint& _ipEndPoint);
	~UDPSession();

	UDPSession(const UDPSession& _other) = delete;
	UDPSession(UDPSession&& _other) = delete;
	UDPSession& operator=(const UDPSession& _other) = delete;
	UDPSession& operator=(const UDPSession&& _other) = delete;

private:
	// UPD IO �̺�Ʈ �߻��� ȣ��� �Լ�
	static void OnIOCallBack(BOOL _result, DWORD _numberOfBytes, LPOVERLAPPED _lpOverlapped);

public: // member Func

	// iocp workqueue�� ���ϵ��
	bool BindQueue(const ServerQueue& _workQueue);

	// ���ú� ��û
	void RequestRecv();

	// recvFrom���� �����Ͱ� ���ð�� recv overlapped���� ȣ��Ǵ� �Լ�
	void OnRecv(const char* _data, DWORD _byteSize);

	void SetRecvCallBack(RecvCallBack _recvCallback);

	// EndPoint
	const IPEndPoint& GetEndPoint() { return m_localAddr; }

	// Send
	void Send(const std::vector<unsigned char>& _buffer, const IPEndPoint& _userEndPoint);
	void OnSendComplete(UDPSendOverlapped* _sendOverlapped);
};
