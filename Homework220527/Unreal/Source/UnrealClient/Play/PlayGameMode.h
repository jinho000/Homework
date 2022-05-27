// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "Character/ClientCharacter.h"
#include "Character/ClientPlayCharacter.h"
#include "../Packets/ClientPackets/ContentStruct.h"
#include "PlayGameMode.generated.h"


/**
 * 
 */
UCLASS()
class UNREALCLIENT_API APlayGameMode : public AGameMode
{
	GENERATED_BODY()
	
private:
	// OtherCharacter�� �����ϱ� ���� Ŭ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ClientData", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AClientCharacter> OtherPlayerClass;

private:
	// OtherCharacter�� ó���ϱ����� �����̳�
	TMap<uint64_t, AActor*> m_allOtherCharacter;

public:
	FORCEINLINE TSubclassOf<AClientCharacter> GetOtherPlayerClass()
	{
		return OtherPlayerClass;
	}

public:
	virtual void BeginPlay() override;


public:
	void SpawnOtherPlayer(const std::vector<uint64_t>& arryOtherPlayerID);
	void UpdateOtherPlayerInfo(const std::vector<FPlayerUpdateData>& _allPlayerInfo);
};
