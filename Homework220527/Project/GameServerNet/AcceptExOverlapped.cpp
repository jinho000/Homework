#include "pch.h"
#include <GameServerBase/ServerDebug.h>

#include "AcceptExOverlapped.h"
#include "TCPSession.h"

AcceptExOverlapped::AcceptExOverlapped(TCPSession* _tcpSession)
	: m_buffer{}
	, m_tcpSession(_tcpSession)
{
}

void AcceptExOverlapped::Excute(BOOL _result, DWORD _byteSize)
{
	if (nullptr == m_tcpSession)
	{
		ServerDebug::LogError("������ ���õǾ� ���� ���� �������� ��ü");
		return;
	}

	// AcceptEx�Լ����� �ּҰ��� ���� ��
	SOCKADDR_IN* pLocalAddr = nullptr;
	SOCKADDR_IN* pRemoteAddr = nullptr;

	int localLen = 0;
	int RemoteLen = 0;

	GetAcceptExSockaddrs(m_buffer,
		0,
		sizeof(sockaddr_in) + 16,
		sizeof(sockaddr_in) + 16,
		(LPSOCKADDR*)&pLocalAddr,
		&localLen,
		(LPSOCKADDR*)&pRemoteAddr,
		&RemoteLen);

	// ����Ʈ ����� ���´�.
	char ArrLocalAddr[4];
	memcpy_s(ArrLocalAddr, 4, &pLocalAddr->sin_addr.s_addr, 4);

	char ArrRemoteAddr[4];
	memcpy_s(ArrRemoteAddr, 4, &pRemoteAddr->sin_addr.s_addr, 4);

	// ���ǿ� ����, Ŭ���ּ� ����
	m_tcpSession->m_localAddr  = IPEndPoint(pLocalAddr->sin_addr.s_addr, htons(pLocalAddr->sin_port));
	m_tcpSession->m_remoteAddr = IPEndPoint(pRemoteAddr->sin_addr.s_addr, htons(pRemoteAddr->sin_port));
}

void* AcceptExOverlapped::GetBuffer()
{
	return m_buffer;
}


PtrSTCPSession AcceptExOverlapped::GetTCPSession()
{
	return std::dynamic_pointer_cast<TCPSession>(m_tcpSession->shared_from_this());
}
