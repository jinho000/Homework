// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Types/SlateEnums.h"

#include "CChatWindow.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCLIENT_API UCChatWindow : public UUserWidget
{
	GENERATED_BODY()

public: 
	// ������ ���� ���� (���������� = �����̸�)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UListView* MessageList;

	// �Է� �ؽ�Ʈ
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chatting")
	FString InputText;

public:
	void NativeConstruct() override;

public:
	UFUNCTION(BlueprintCallable, Category = "Chatting")
	void AddChatMessage(UObject* _chatMsgObj, UUserWidget* _chatMsgWidget);
	
	void AddChatMessage(class UCChatMessage* _chatMassage);

	UFUNCTION(BlueprintCallable, Category = "Chatting")
	void OnChatMsgCommitted(const FString& _text, ETextCommit::Type _commitType);
};
