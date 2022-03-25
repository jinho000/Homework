#include "ThreadHandlerJoinResultMessage.h"
#include "../../Global/ClientGameInstance.h"
#include "Kismet/GameplayStatics.h"


ThreadHandlerJoinResultMessage::ThreadHandlerJoinResultMessage(std::shared_ptr<JoinResultMessage> _JoginMessage)
	: JoginResultMessage_(_JoginMessage)
{
}

void ThreadHandlerJoinResultMessage::Init(UClientGameInstance* _Inst, UWorld* _World)
{
	Inst_ = _Inst;
	World_ = _World;
}

void ThreadHandlerJoinResultMessage::Start()
{
	if (EGameServerCode::OK == JoginResultMessage_->Code)
	{
		UE_LOG(LogTemp, Log, TEXT("Join OK"));
		return;
	}

	if (EGameServerCode::JoinIDError == JoginResultMessage_->Code)
	{
		UE_LOG(LogTemp, Log, TEXT("Join Fail"));
		return;
	}
}
