#include "JoginResultPacketHandler.h"
#include <Kismet/GameplayStatics.h>
#include "../../Global/CGameInstance.h"
#include "../../Login/JoinUI.h"
#include "../../Login/CLoginUI.h"

void JoginResultPacketHandler::Start()
{
	UE_LOG(LogTemp, Log, TEXT("JoginResultPacketHandler"));

	// ȸ������ �Ϸ�
	if (EJoinResultCode::OK == m_packet->JoginResultCode)
	{
		UE_LOG(LogTemp, Log, TEXT("Join OK"));
		m_pGameInst->JoinUI->SetVisibility(ESlateVisibility::Hidden);
		m_pGameInst->LoginUI->LoginStatus = TEXT("Join OK");
		return;
	}

	// ���̵� �ߺ�
	if (EJoinResultCode::ID_DUPLE == m_packet->JoginResultCode)
	{
		UE_LOG(LogTemp, Log, TEXT("ID is already exist"));
		m_pGameInst->JoinUI->JoinState = TEXT("ID is already exist");
		return;
	}
}

