// Fill out your copyright notice in the Description page of Project Settings.


#include "JoinUI.h"
#include "../Global/CGameInstance.h"
#include "../Packets/ClientPackets/Packets.h"

void UJoinUI::NativeConstruct()
{
	UUserWidget::NativeConstruct();

	UCGameInstance* Inst = Cast<UCGameInstance>(GetGameInstance());
	Inst->JoinUI = this;

	SetVisibility(ESlateVisibility::Hidden);
	SetVisibility(ESlateVisibility::Visible);
}

bool UJoinUI::Join()
{
	UE_LOG(LogTemp, Log, TEXT("Join"));
	UE_LOG(LogTemp, Log, TEXT("user id: %s"), *ID);

	UCGameInstance* gameInst = Cast<UCGameInstance>(GetGameInstance());

	// ������ ���� ���� ����
	JoinPacket packet;
	packet.ID = std::string(FTCHARToUTF8(*ID).Get());
	packet.PW = std::string(FTCHARToUTF8(*Password).Get());

	ServerSerializer sr;
	packet >> sr;

	

	return gameInst->SendBytes(sr.GetBuffer());
}
