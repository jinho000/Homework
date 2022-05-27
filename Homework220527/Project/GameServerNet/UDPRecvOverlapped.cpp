#include "pch.h"
#include "UDPRecvOverlapped.h"
#include "UDPSession.h"

UDPRecvOverlapped::UDPRecvOverlapped(UDPSession* _udpSession)
	: m_buffer{}
	, m_wsaBuffer{}
	, m_numberofBytes()
	, m_udpSession(_udpSession)
{
	memset(m_buffer, 0x00, sizeof(m_buffer));
	m_wsaBuffer.buf = m_buffer;
	m_wsaBuffer.len = static_cast<ULONG>(sizeof(m_buffer));
	m_numberofBytes = 0;
}


UDPRecvOverlapped::~UDPRecvOverlapped()
{
}

void UDPRecvOverlapped::Clear()
{
	memset(m_buffer, 0x00, sizeof(m_buffer));
	m_wsaBuffer.len = sizeof(m_buffer);
	m_wsaBuffer.buf = m_buffer;
}

void UDPRecvOverlapped::Excute(BOOL Result, DWORD _ByteSize)
{
	// tcp�� ������ Ŭ���̾�Ʈ���� session�� ����
	// udp�� server core�� ������ ����
	// recv�̺�Ʈ�� �� �����忡�� Excute ȣ��
	// �ϳ��� udp������ ���� �����忡�� ����� ���ɼ� ����


	// UDP�� ������ ���� �ʿ䰡 ����
	// recvCallback ȣ�� �ʿ���� �ٽ� ���ú��û ����
	if (0 == _ByteSize)
	{
		m_udpSession->RequestRecv();
		return;
	}

	m_udpSession->OnRecv(m_buffer, _ByteSize);
}

void* UDPRecvOverlapped::GetBuffer()
{
	return m_buffer;
}

LPWSABUF UDPRecvOverlapped::GetWSABuffer()
{
	return &m_wsaBuffer;
}

LPDWORD UDPRecvOverlapped::GetBufferLength()
{
	return &m_numberofBytes;
}
