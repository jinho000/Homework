#include "PreCompile.h"
#include "ThreadHandlerJoinMessage.h"

#include <GameServerCore/NetQueue.h>

#include "UserTable.h"

ThreadHandlerJoinMessage::ThreadHandlerJoinMessage()
{
}

ThreadHandlerJoinMessage::~ThreadHandlerJoinMessage()
{
}

void ThreadHandlerJoinMessage::DBCheck()
{
	GameServerSerializer Sr;

	UserTable_SelectIDToUserInfo SelectQuery(Message_->ID);
	if (true == SelectQuery.DoQuery())
	{
		// ���� ���̵� �̹� ����
		JoginResult_.Code = EGameServerCode::JoinIDError;
		JoginResult_.Serialize(Sr);
		TCPSession_->Send(Sr.GetData());
		return;
	}

	UserTable_InsertUserInfo insertQuery = UserTable_InsertUserInfo(Message_->ID, Message_->PW);
	if (false == insertQuery.DoQuery())
	{
		// ��� ���� ����
		GameServerDebug::AssertDebugMsg("Fail Insert Query");
		return;
	}

	JoginResult_.Code = EGameServerCode::OK;
	JoginResult_.Serialize(Sr);
	TCPSession_->Send(Sr.GetData());
}

void ThreadHandlerJoinMessage::ResultSend()
{

}

void ThreadHandlerJoinMessage::Start()
{
	if (nullptr == TCPSession_)
	{
		GameServerDebug::LogError("Login TCPSession Error");
	}

	//LoginResult_.Code = EGameServerCode::LoginError;
	DBWork(&ThreadHandlerJoinMessage::DBCheck);
}

