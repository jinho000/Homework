// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CharacterSelectUI.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCLIENT_API UCharacterSelectUI : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharaterSelectUI")
	class UListView* CharacterListView;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharaterSelectUI")
	FString State;

	class UCharacterListItem* UpdateItem;

public:
	void NativeConstruct() override;

public:
	// UFUNCTION: �������Ʈ���� �Լ��� ����ϱ� ���� ����
	UFUNCTION(BlueprintCallable, Category = "CharaterSelectUI")
	void AddItemToListEvent(UObject* _Object, UUserWidget* _Widget);

};
