#include "SpawnOtherPlayerPacketHandler.h"	
#include <Kismet/GameplayStatics.h>
#include "../../Play/PlayGameMode.h"

void SpawnOtherPlayerPacketHandler::Start()
{
	// �������ִ� ��� ������ ĳ���� ������Ŷ�� �޴´�
	//APlayGameMode* pPlayGameMode = Cast<APlayGameMode>(UGameplayStatics::GetGameMode(m_pWorld));

	//const std::vector<FPlayerUpdateData>& allPlayerInfo = m_packet->AllPlayerInfo;
	//for (const FPlayerUpdateData& playerInfo : allPlayerInfo)
	//{
	//	// ��� �÷��̾��� ������ �����Ƿ� �� ������ ���� ó���ؾ��Ѵ�
	//	if (playerInfo.PlayerID == m_pGameInst->GetPlayerID())
	//	{
	//		continue;
	//	}

	//	pPlayGameMode->SpawnOtherPlayer(playerInfo);
	//}
}

