// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameMode.h"

#include "../Global/CGameInstance.h"
#include "../Packets/ClientPackets/Packets.h"

void ALobbyGameMode::BeginPlay()
{
	Super::BeginPlay();

	// ���� ���Խ�, �÷��̾� ������ UDP���� ���� 
	// UPD ��� ó���� ���� ������� �÷��̸�忡�� ����
	UCGameInstance* gameInst = Cast<UCGameInstance>(GetGameInstance());
	gameInst->ConnectUDPServer();

	// �÷��̾� ó�� ��ġ�� ��Ʈ�� ������ TCP�� ����
	UDPStartPacket packet;
	packet.udpPort = gameInst->GetUnrealUDPPort();

	ServerSerializer sr;
	packet >> sr;
	gameInst->SendBytes(sr.GetBuffer());
}

