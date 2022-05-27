// Fill out your copyright notice in the Description page of Project Settings.


#include "PacketComponent.h"
#include "ClientPackets/Packets.h"
#include "PacketHandler/PacketHandlerHeader.h"


// Sets default values for this component's properties
UPacketComponent::UPacketComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	m_pGameInst = nullptr;
}

// Called when the game starts
void UPacketComponent::BeginPlay()
{
	Super::BeginPlay();

	// ���⼭ ó���� �ڵ鷯 �߰�
	UE_LOG(LogTemp, Log, TEXT("Packet Component Begin Play"));

	RegistPacketHandler();
}


// Called every frame
void UPacketComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ���ú� ť�� �ִ� ��Ŷ�� ��� ���� �ڵ鷯�� ó��
	TQueue<std::shared_ptr<ServerPacketBase>>& packetQueue = m_pGameInst->GetPacketQueue();

	while (false == packetQueue.IsEmpty())
	{
		std::shared_ptr<ServerPacketBase> packet;
		packetQueue.Dequeue(packet);
		PacketType type = packet->GetPacketType();
		auto iter = m_handlerContainer.find(type);
		ClientPacketHandler handler = iter->second;
		
		if (nullptr == handler)
		{
			UE_LOG(LogTemp, Log, TEXT("packet handler is nullptr"));
			continue;
		}

		UE_LOG(LogTemp, Log, TEXT("start packet handler"));
		(handler)(packet);
	}
}

#include "RegistPacketHandler.h"
