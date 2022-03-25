#pragma once
#include "CoreMinimal.h"
#include <Memory>
#include "../Messages.h"

class ThreadHandlerJoinResultMessage
{
private:
	class UWorld* World_;
	class UClientGameInstance* Inst_;
	std::shared_ptr<JoinResultMessage> JoginResultMessage_;


public: // default
	ThreadHandlerJoinResultMessage(std::shared_ptr<JoinResultMessage> _JoginMessage);

	// �� �޼����� ó�� �޾����� �����ϴ� �Լ�
	void Init(UClientGameInstance* _Inst, UWorld* _World);
	void Start();
};

