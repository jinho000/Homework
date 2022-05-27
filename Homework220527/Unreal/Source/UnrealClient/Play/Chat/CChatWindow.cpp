// Fill out your copyright notice in the Description page of Project Settings.


#include "CChatWindow.h"
#include <Components/ListView.h>

#include "CChatMsgWidget.h"
#include "CChatMessage.h"
#include "../../Packets/ClientPackets/ClientToServer.h"
#include "../../Packets/ClientPackets/ServerToClient.h"
#include "../../Packets/ClientPackets/ServerAndClient.h"
#include "../../Packets/ClientPackets/ServerSerializer.h"
#include "../../Global/CGameInstance.h"

void UCChatWindow::NativeConstruct()
{
	UCGameInstance* Inst = Cast<UCGameInstance>(GetGameInstance());
	Inst->SetChatWindow(this);
}

// ä�ø���Ʈ�� ä�������� �߰��� ��� ���� �Լ�
void UCChatWindow::AddChatMessage(UObject* _chatMsgObj, UUserWidget* _chatMsgWidget)
{
	UE_LOG(LogTemp, Log, TEXT("AddChatMessage"));

	UCChatMessage* pChatMessage = Cast<UCChatMessage>(_chatMsgObj);
	UCChatMsgWidget* pMsgWidget = Cast<UCChatMsgWidget>(_chatMsgWidget);

	// ä������ �Էµ� ��츸 ó��
	if (nullptr == pChatMessage || nullptr == pMsgWidget)
	{
		return;
	}

	FString msg = pChatMessage->GetChatMessage();
	pMsgWidget->Message = msg;
}

void UCChatWindow::AddChatMessage(UCChatMessage* _chatMassage)
{
	MessageList->AddItem(_chatMassage);
	MessageList->SetScrollOffset(MessageList->GetNumItems() * 50.0f);
}

void UCChatWindow::OnChatMsgCommitted(const FString& _chatMessage, ETextCommit::Type _commitType)
{
	// enter �Է��ΰ�츸 ó��
	if (ETextCommit::Type::OnEnter != _commitType)
	{
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("OnChatMsgCommitted"));
	
	UCGameInstance* gameInst = Cast<UCGameInstance>(GetGameInstance());
	ChatMessagePacket packet;
	FCharacterInfo currCharacter = gameInst->SelectCharacter;
	packet.NickName = currCharacter.NickName;
	packet.Message = FTCHARToUTF8(*_chatMessage).Get();

	ServerSerializer sr;
	packet >> sr;
	gameInst->SendBytes(sr.GetBuffer());

	// �Է� ����
	InputText.Empty();

	FString nickName = FUTF8ToTCHAR(packet.NickName.c_str()).Get();
	UE_LOG(LogTemp, Log, TEXT("Send NickName: %s"), *nickName);
	UE_LOG(LogTemp, Log, TEXT("Send Message: %s"), *_chatMessage);
}