#include "GameMatchPacketHandler.h"
#include <Kismet/GameplayStatics.h>
#include "../../Lobby/LobbyGameMode.h"


void GameMatchPacketHandler::Start()
{
	// �÷��� ���� �̵�
	UGameplayStatics::OpenLevel(m_pWorld, TEXT("PlayLevel"));

	// ���ӷκ񿡼� ���� UDP���� ��Ŷ��� �޾� ����
	// ���ǹ�ȣ, �÷��̾� �ε���, �ٸ� �÷��̾� �ε��� ����
	m_pGameInst->SetSessionIdx(m_packet->sessionIdx);
	m_pGameInst->SetPlayerIdx(m_packet->playerIdx);
	
	std::vector<uint64_t> otherPlayerID;
	for (size_t i = 0; i < m_packet->AllPlayerInfo.size(); i++)
	{
		// �ٸ� �÷��̾��� ���̵� ����
		if (m_packet->AllPlayerInfo[i].PlayerID == m_pGameInst->GetPlayerID())
		{
			continue;
		}

		otherPlayerID.push_back(m_packet->AllPlayerInfo[i].PlayerID);
	}

	m_pGameInst->SetOtherPlayerID(otherPlayerID);
}
