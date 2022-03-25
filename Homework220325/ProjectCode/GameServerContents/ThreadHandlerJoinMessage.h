#pragma once
#include <GameServerCore\ThreadHandlerBase.h>


// �뵵 :
// �з� :
// ÷�� :
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
	// �� �޼����� ó���ϴ� �ܰ�
	void DBCheck();
	
	// �� �޼����� ó���� �������� ����Ǵ� �Լ�
	void ResultSend();

public: // member Func
	
	// �� �޼����� ó�� �޾����� �����ϴ� �Լ�
	void Start() override;
};

