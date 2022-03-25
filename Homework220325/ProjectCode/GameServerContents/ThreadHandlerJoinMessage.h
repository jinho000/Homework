#pragma once
#include <GameServerCore\ThreadHandlerBase.h>


// 용도 :
// 분류 :
// 첨언 :
class ThreadHandlerJoinMessage final
	: public ThreadHandlerBase<JoinMessage>
{
private: // member var
	JoinResultMessage JoginResult_;

public: // default
	ThreadHandlerJoinMessage();
	~ThreadHandlerJoinMessage();

	ThreadHandlerJoinMessage(const ThreadHandlerJoinMessage& _other) = delete;
	ThreadHandlerJoinMessage(ThreadHandlerJoinMessage&& _other) noexcept = delete;
	ThreadHandlerJoinMessage& operator=(const ThreadHandlerJoinMessage& _other) = delete;
	ThreadHandlerJoinMessage& operator=(const ThreadHandlerJoinMessage&& _other) = delete;

private:
	// 이 메세지를 처리하는 단계
	void DBCheck();
	
	// 이 메세지가 처리가 끝났을때 실행되는 함수
	void ResultSend();

public: // member Func
	
	// 이 메세지를 처음 받았을때 실행하는 함수
	void Start() override;
};

