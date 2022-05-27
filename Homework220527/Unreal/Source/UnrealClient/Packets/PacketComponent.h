// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <functional>
#include <memory>
#include <map>

#include "../Global/CGameInstance.h"
#include "Components/ActorComponent.h"
#include "ClientPackets/ServerPacketBase.h"
#include "PacketComponent.generated.h"

using ClientPacketHandler = std::function<void(std::shared_ptr<ServerPacketBase>)>;

//��Ŷ�� �޽��� ������Ʈ���� �������Ӹ��� ƽ�� ���� ť���ִ� ��Ŷ�� ó��
//���Ӹ�忡 �޽���������Ʈ�� �߰�
//(��Ŷ�� ƽ���� Ȯ���Ͽ� ó���ؾ��ϱ� ����,
//	�����ν��Ͻ����� ƽ�Լ��� ����
//	�� ���Ӹ�帶�� �޽��� ������Ʈ�� �߰��Ͽ� ƽ���� ó��
//	���Ӹ���� ƽ�� ��ƽ���� ó������ ����
//)
// 
// ���ú� ��Ŷ�� ó���ϱ� ���� ��Ŷ ������Ʈ
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALCLIENT_API UPacketComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	std::map<PacketType, ClientPacketHandler> m_handlerContainer;
	UCGameInstance* m_pGameInst;
	
public:	
	// Sets default values for this component's properties
	UPacketComponent();

private:
	template<class HandlerClass, class PacketType>
	static void ProcessHandler(std::shared_ptr<ServerPacketBase> _packet, UCGameInstance* _instance, UWorld* _world)
	{
		std::shared_ptr<PacketType> packet = std::static_pointer_cast<PacketType>(_packet);
		if (nullptr == packet)
		{
			UE_LOG(LogTemp, Error, TEXT("packet nullptr"));
			return;
		}

		HandlerClass handler;
		handler.Init(_instance, _world, packet);
		handler.Start();
	}

	void RegistPacketHandler();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
