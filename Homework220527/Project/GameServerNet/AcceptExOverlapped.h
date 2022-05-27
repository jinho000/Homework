#pragma once
#include "Overlapped.h"
// �뵵 : AcceptEx���� ����ϴ� Overlapped ������
// �з� :
// ÷�� :
class AcceptExOverlapped : public Overlapped
{
private: // member var
	char		m_buffer[128]; // local, remote �ּҰ��� �����ϱ����� ���
	TCPSession* m_tcpSession;


public: // default
	AcceptExOverlapped(TCPSession* _tcpSession);
	~AcceptExOverlapped() = default;

	AcceptExOverlapped(const AcceptExOverlapped& _other) = delete;
	AcceptExOverlapped(AcceptExOverlapped&& _other) = delete;
	AcceptExOverlapped& operator=(const AcceptExOverlapped& _other) = delete;
	AcceptExOverlapped& operator=(const AcceptExOverlapped&& _other) = delete;

private:

public: // member Func
	void Excute(BOOL _result, DWORD _byteSize);
	void* GetBuffer();
	PtrSTCPSession GetTCPSession();

};

