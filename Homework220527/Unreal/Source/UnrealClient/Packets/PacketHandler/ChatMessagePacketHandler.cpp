#include "ChatMessagePacketHandler.h"
#include <Kismet/GameplayStatics.h>
#include "../../Play/Chat/CChatMessage.h"
#include "../../Global/CGameInstance.h"
#include "../../Play/Chat/CChatWindow.h"

void ChatMessagePacketHandler::Start()
{
	UE_LOG(LogTemp, Log, TEXT("ChatMessagePacketHandler"));

	// ��Ŷ �м�
	FString nickName = FUTF8ToTCHAR(m_packet->NickName.c_str()).Get();
	FString message = FUTF8ToTCHAR(m_packet->Message.c_str()).Get();

	// ä�� ������Ʈ 
	UCChatMessage* chatMessage = NewObject<UCChatMessage>();
	chatMessage->Init(nickName, message);

	// ä�������쿡 ä������
	UCChatWindow* pChatWindow = m_pGameInst->GetChatWindow();
	pChatWindow->AddChatMessage(chatMessage);

	UE_LOG(LogTemp, Log, TEXT("Recv NickName: %s"), *nickName);
	UE_LOG(LogTemp, Log, TEXT("Recv Message: %s"), *message);
}

