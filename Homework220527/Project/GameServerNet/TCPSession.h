#pragma once
#include "IPEndPoint.h"
#include "GameServerBase/ServerBaseObject.h"
#include "GameServerBase/ServerQueue.h"
#include "GameServerBase/ServerObjectPool.h"
#include "SendOverlapped.h"
#include "AcceptExOverlapped.h"
#include "TCPListener.h"

// Ŭ���̾�Ʈ�� ������ ����
class RecvOverlapped;
class AcceptExOverlapped;
class DisconnectOverlapped;
class TCPSession : public ServerBaseObject
{
private:
	// friend class
	friend class TCPListener;
	friend class RecvOverlapped;
	friend class AcceptExOverlapped;
	friend class DisconnectOverlapped;
	friend class SendOverlapped;

private: // member var
	__int64		m_conectId;
	SOCKET		m_sessionSocket;
	IPEndPoint	m_localAddr;
	IPEndPoint	m_remoteAddr;

	// ������ ����ȭ�� �����Ѱ�?
	// overlapped
	AcceptExOverlapped*		m_acceptExOverlapped;
	RecvOverlapped*			m_recvOverlapped;
	DisconnectOverlapped*	m_disconOverlapped;

	// send�� ���ÿ� ������ ������ �־���� (Sendpool)
	SendOverlapped*			m_sendOverlapped;

	// callback
	using IOCallback = std::function<void(BOOL, DWORD, LPOVERLAPPED)>;
	IOCallback				m_IOCallback; // ���Ǽ��� IO�̺�Ʈ �߻��� ȣ���Լ� �Լ���ü

	using RecvCallBack = std::function<void(PtrSTCPSession, const std::vector<uint8_t>&)>;
	RecvCallBack			m_recvCallBack; // Ŭ���̾�Ʈ�� ���ú� ������ ó���Լ�

	using CloseCallBack = std::function<void(PtrSTCPSession)>;
	CloseCallBack			m_closeCallBack;

	//ServerObjectPool<SendOverlapped> m_sendPool;

	std::atomic_bool		m_callClose;
	std::atomic_bool		m_bReuseSocket;

public: // default
	TCPSession();
	~TCPSession();

	TCPSession(const TCPSession& _other) = delete;
	TCPSession(TCPSession&& _other) = delete;
	TCPSession& operator=(const TCPSession& _other) = delete;
	TCPSession& operator=(const TCPSession&& _other) = delete;

private:
	// friend class ����
	void Initialize();
	AcceptExOverlapped* GetAcceptExOverlapped() { return m_acceptExOverlapped; }

private:
	// ���Ǽ��Ͽ� IO�̺�Ʈ �߻��� ȣ���Լ�
	void OnCallback(BOOL _result, DWORD _numberOfBytes, LPOVERLAPPED _lpOverlapped);

	// workQueue�� ���Ǽ��� ����(���)
	bool BindQueue(const ServerQueue& _workQueue);
	void SetReuse();
	
	void RequestRecv();
	void OnRecv(const char* _data, DWORD _byteSize);


	void CloseSession(bool _forceClose = false);
	void CloseSocket();
	void UnregisterSession();

public: // member Func
	SOCKET GetSessionSocket() const;
	__int64 GetSessionID() const { return m_conectId; };
	void SetCallBack(RecvCallBack _recvCallBack, CloseCallBack _closeCallBack);
	void Send(const std::vector<uint8_t>& _buffer);

	TCPListener* GetTCPListener() { return GetParent<TCPListener>(); }
	const IPEndPoint& GetRemoteIPEndPoint() { return m_remoteAddr; }
};
