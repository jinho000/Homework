#include "pch.h"
#include "UDPStartPacketHandler.h"
#include <GameServerNet/TCPSession.h>
#include <GameServerCore/ServerCore.h>
#include "ContentManager.h"
#include "PacketHeader.h"
#include "ClientPlayer.h"

void UDPStartPacketHandler::InitUDP(PtrSUDPSession _UDPSession, std::shared_ptr<UDPStartPacket> _packet, const IPEndPoint& _clientEndPoint)
{
	m_UDPSession = _UDPSession;
	m_packet = _packet;
	m_clientEndPoint = _clientEndPoint;
}

// 
// �κ� -> ������û(10) -> ����1(10); <-> ::
void UDPStartPacketHandler::Start()
{
	// udp ����� ���� Ŭ���̾�Ʈ endpoint ����
	IPEndPoint clientEndPoint(m_TCPSession->GetRemoteIPEndPoint().GetIPAddress(), m_packet->udpPort);

	// ������ ��������
	// ContentManager���� ���ӷκ� endpoint, player ID ����
	std::shared_ptr<ClientPlayer> pClientPlayer = std::make_shared<ClientPlayer>();
	ContentManager::GetInst()->AddUserToLobby(pClientPlayer, clientEndPoint, m_TCPSession);

	// �÷��̾�� ������ �������̵� ����
	UDPStartResultPacket packet;
	packet.PlayerID = pClientPlayer->GetPlayerID();

	ServerSerializer sr;
	packet >> sr;
	m_TCPSession->Send(sr.GetBuffer());


}
