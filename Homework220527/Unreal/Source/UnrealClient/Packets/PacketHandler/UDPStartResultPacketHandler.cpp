#include "UDPStartResultPacketHandler.h"	
#include <Kismet/GameplayStatics.h>
#include "../../Lobby/LobbyGameMode.h"
#include "../../Global/CGameInstance.h"

void UDPStartResultPacketHandler::Start()
{
	// ���ӷκ񿡼� ���� UDP���� ��Ŷ��� �޾� ����
	m_pGameInst->SetPlayerID(m_packet->PlayerID);
}
