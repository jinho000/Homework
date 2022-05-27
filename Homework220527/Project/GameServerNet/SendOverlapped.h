#pragma once
#include "Overlapped.h"
// �뵵 :
// �з� :
// ÷�� :
class SendOverlapped : public Overlapped
{
private: // member var
	std::vector<char>	m_buffer;
	WSABUF				m_wsaBuff;
	TCPSession*			m_tcpSession;

public: // default
	SendOverlapped(TCPSession* _tcpSession);
	~SendOverlapped();

	SendOverlapped(const SendOverlapped& _other) = delete;
	SendOverlapped(SendOverlapped&& _other) = delete;
	SendOverlapped& operator=(const SendOverlapped& _other) = delete;
	SendOverlapped& operator=(const SendOverlapped&& _other) = delete;

private:
	void New(size_t _maxBufferLength); // ���ο� ���� ����

public: // member Func
	void Clear();
	void Excute(BOOL _result, DWORD _byteSize) override;
	void CopyFrom(const std::vector<uint8_t>& _from); // �ܺο��� ������ ���۸� ����

	int GetMaxBufferLength();
	LPWSABUF GetBuffer();
};

