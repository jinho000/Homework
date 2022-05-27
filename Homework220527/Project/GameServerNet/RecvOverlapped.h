#pragma once
#include "Overlapped.h"

// �뵵 :
// �з� :
// ÷�� :
class RecvOverlapped : public Overlapped
{
private: // member var
	char		m_Buffer[1024]; // ���޹��� ������
	WSABUF		m_wsaBuffer;
	TCPSession* m_tcpSession;

public: // default
	RecvOverlapped(TCPSession* _tcpSession);
	~RecvOverlapped();

	RecvOverlapped(const RecvOverlapped& _other) = delete;
	RecvOverlapped(RecvOverlapped&& _other) = delete;

protected:
	RecvOverlapped& operator=(const RecvOverlapped& _other) = delete;
	RecvOverlapped& operator=(const RecvOverlapped&& _other) = delete;

private:

public: // member Func
	void Clear();
	void Excute(BOOL Result, DWORD _ByteSize) override;
	void* GetBuffer();
	LPWSABUF GetWSABuffer();
	PtrSTCPSession GetTCPSession();
};

