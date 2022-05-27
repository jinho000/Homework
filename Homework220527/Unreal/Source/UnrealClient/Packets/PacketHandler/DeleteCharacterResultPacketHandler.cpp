#include "DeleteCharacterResultPacketHandler.h"
#include "../../Global/CGameInstance.h"
#include "../../CharacterSelect/CharacterSelectItemObj.h"
#include "../../Global/CBlueprintFunctionLibrary.h"
#include "../../CharacterSelect/CharacterSelectUI.h"
#include "../../CharacterSelect/CharacterListItem.h"
#include "../../Global/CBlueprintFunctionLibrary.h"

void DeleteCharacterResultPacketHandler::Start()
{
	UE_LOG(LogTemp, Log, TEXT("DeleteCharacterResultPacketHandler"));

	if (EResultCode::OK != m_packet->ResultCode)
	{
		m_pGameInst->CharacterSelectUI->UpdateItem = nullptr;
		m_pGameInst->CharacterSelectUI->State = TEXT("Delete Character Fail");
		UE_LOG(LogTemp, Log, TEXT("Delete Character Fail"));
		return;
	}

	// ���Ӹ���ν��Ͻ��� ĳ���� ���� ����
	FString deleteNickName;
	UCBlueprintFunctionLibrary::UTF8ToFString(m_packet->DeleteCharNickName, deleteNickName);
	UE_LOG(LogTemp, Log, TEXT("Delete NickName %s"), *deleteNickName);
	m_pGameInst->DeleteCharacter(m_packet->DeleteCharNickName);


	// UI ����Ʈ�� ����
	UE_LOG(LogTemp, Log, TEXT("Update UI Listview"));
	m_pGameInst->CharacterSelectUI->State = TEXT("Delete Character OK");
	m_pGameInst->CharacterSelectUI->UpdateItem->HideItem();
	m_pGameInst->CharacterSelectUI->UpdateItem = nullptr;
}
