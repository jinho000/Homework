#include "SelectCharacterResultPacketHandler.h"
#include <Kismet/GameplayStatics.h>
#include "../../Global/CBlueprintFunctionLibrary.h"
#include "../../Global/CGameInstance.h"
#include "../../Packets/ClientPackets/Packets.h"

void SelectCharacterResultPacketHandler::Start()
{
	UE_LOG(LogTemp, Log, TEXT("SelectCharacterResultPacketHandler"));

	if (EResultCode::OK != m_packet->ResultCode)
	{
		m_pGameInst->LoginProcess = false;
		UE_LOG(LogTemp, Log, TEXT("Result Code FAIL"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Result Code OK"));

	// �ε��̰� ���� ��� ����.
	// ���� Ŭ�� �Ұ� ����
	// ���������
	// �ε� ����Ͻø� �˴ϴ�.
	FString nickName;
	UCBlueprintFunctionLibrary::UTF8ToFString(m_packet->SelectCharNickName, nickName);

	UE_LOG(LogTemp, Log, TEXT("Check Packet NickName"));
	const std::vector<FCharacterInfo>& characterList = m_pGameInst->UserCharacterList;
	for (size_t i = 0; i < characterList.size(); i++)
	{
		if (characterList[i].NickName == m_packet->SelectCharNickName)
		{
			// ���޹��� ��Ŷ�� �г��� ���� �Ϸ�
			UE_LOG(LogTemp, Log, TEXT("Check NickName OK: %s"), *nickName);
			m_pGameInst->SelectCharacter = characterList[i];
			m_pGameInst->LoginProcess = true;

			UE_LOG(LogTemp, Log, TEXT("GameSession Number %d"), (int)m_packet->GameSessionType);

			// �������� �̵�
			UGameplayStatics::OpenLevel(m_pWorld, TEXT("Lobby"));
			return;
		}
	}

	// ���� ĳ���� �̸��� ���޹��� ĳ�����̸��� �ٸ��Ƿ� ���ý���
	// �ʱ� �α���ȭ������ ���ư���
	UE_LOG(LogTemp, Log, TEXT("Check NickName FAIL"));
	UE_LOG(LogTemp, Error, TEXT("%S(%u) > Charcter Client Data FAIL"), __FUNCTION__, __LINE__);
	m_pGameInst->LoginProcess = false;
	UGameplayStatics::OpenLevel(m_pWorld, TEXT("LoginLevel"));
}
