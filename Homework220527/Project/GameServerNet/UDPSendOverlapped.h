#pragma once
#include "Overlapped.h"

// �뵵 :
// �з� :
// ÷�� :
class UDPSendOverlapped : public Overlapped
{
private: // member var
	char				m_buffer[1024];
	WSABUF				m_wsaBuff;
	DWORD				m_numberofBytes;
	UDPSession*			m_udpSession;

public: // default
	UDPSendOverlapped(UDPSession* _udpSession);
	~UDPSendOverlapped();

	UDPSendOverlapped(const UDPSendOverlapped& _other) = delete;
	UDPSendOverlapped(UDPSendOverlapped&& _other) = delete;
	UDPSendOverlapped& operator=(const UDPSendOverlapped& _other) = delete;
	UDPSendOverlapped& operator=(const UDPSendOverlapped&& _other) = delete;

public: // member Func
	void Clear();
	void Excute(BOOL _result, DWORD _byteSize) override;
	void CopyFrom(const std::vector<uint8_t>& _from); // �ܺο��� ������ ���۸� ����

	LPDWORD GetBufferLength();
	LPWSABUF GetBuffer(); 
};

