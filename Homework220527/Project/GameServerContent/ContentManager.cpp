#include "pch.h"
#include "ContentManager.h"
#include "PacketHeader.h"
#include "ServerSerializer.h"

ContentManager* ContentManager::Inst = new ContentManager;

void ContentManager::Init()
{
}

ContentManager::ContentManager()
	: m_matchCount(2)
{
}

ContentManager::~ContentManager()
{
}



void ContentManager::AddUserToLobby(const std::shared_ptr<ClientPlayer>& playerCharacterInfo, const IPEndPoint& userEndpoint, const std::shared_ptr<TCPSession>& tcpSession)
{
	std::lock_guard lock(m_lobbyLock);
	m_lobbyUserTable.insert(std::make_pair(playerCharacterInfo->GetPlayerID(), UserInfo{ userEndpoint, tcpSession, playerCharacterInfo }));
}

void ContentManager::AddMatchQueue(uint64_t playerID)
{
	std::lock_guard lock(m_lobbyLock);
	m_matchQueue.push(playerID);

	// ������ ��Ī�Ȱ��
	if (m_matchQueue.size() == m_matchCount)
	{
		// ���ο� ���� ������ �����
		size_t sessionIdx = m_gameSession.size();
		GameSession newSession(m_matchCount, sessionIdx);

		for (size_t i = 0; i < m_matchCount; ++i)
		{
			// �κ������� ������ �̵���Ų��
			uint64_t playerID = m_matchQueue.front(); m_matchQueue.pop();
			auto iter = m_lobbyUserTable.find(playerID);
			newSession.AddUser(iter->second);
			m_lobbyUserTable.erase(playerID);
		}

		// ��Ī�� �����鿡�� ��ε�ĳ����
		// ������ ��Ī�� ��� ��Ī�� �����鿡�� �˸�
		// ���������� ���� �ε���, ���� ������ �ε���, �ٸ������� ���̵� ����
		newSession.BroadCastMachingPacket();

		m_gameSession.push_back(std::move(newSession));
	}
}


void ContentManager::BroadCastTCPInSession(int sessionIdx, const std::shared_ptr<ServerPacketBase>& packet)
{
	m_gameSession[sessionIdx].BroadCastTCP(packet);
}

void ContentManager::BroadCastUDPInSession(int sessionIdx, const std::shared_ptr<ServerPacketBase>& packet, const std::shared_ptr<UDPSession>& udpSession)
{
	m_gameSession[sessionIdx].BroadCastUDP(packet, udpSession);
}

void ContentManager::BroadCastUDPPlayerData(const FPlayerUpdateData& playerData, const std::shared_ptr<UDPSession>& udpSession)
{	
	// ���Ǿȿ��� ���� �ɾ� ó��
	m_gameSession[playerData.SessionIdx].BroadCastUDPPlayerData(playerData, udpSession);
}

