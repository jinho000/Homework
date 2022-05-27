// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LobbyUI.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCLIENT_API ULobbyUI : public UUserWidget
{
	GENERATED_BODY()
	
public:
	// UFUNCTION: �������Ʈ���� �Լ��� ����ϱ� ���� ����
	UFUNCTION(BlueprintCallable, Category = "Lobby")
	void RequestGameMatch();

	UFUNCTION(BlueprintCallable, Category = "Lobby")
	void Cancel();
};
