#include "pch.h"
#include "DeleteCharacterPacketHandler.h"
#include <GameServerBase/ServerString.h>
#include <GameServerNet/TCPSession.h>
#include <GameServerCore/DBQueue.h>
#include <GameServerCore/NetQueue.h>

#include "UserTable.h"
#include "CharacterTable.h"
#include "SessionUserDBData.h"
#include "DBTableEHeader.h"
#include "ContentStruct.h"

void DeleteCharacterPacketHandler::DBThreadWork()
{
	ServerDebug::LogInfo("Check DB");
	m_resultPacket.ResultCode = EResultCode::FAIL;
	m_resultPacket.DeleteCharNickName = m_packet->NickName;

	// �ش� �г����� �ִ��� Ȯ��
	CharacterTable_SelectNickName SelectQuery = CharacterTable_SelectNickName(m_packet->NickName);
	if (false == SelectQuery.DoQuery())
	{
		ServerDebug::LogInfo("Select Query Fail");
		NetQueue::EnQueue(std::bind(&DeleteCharacterPacketHandler::NetThreadSendResult, std::dynamic_pointer_cast<DeleteCharacterPacketHandler>(shared_from_this())));
		return;
	}

	// ������ ������ �ִ� ��s���Ӱ� ��ġ�ϴ��� �˻�
	std::shared_ptr<SessionUserDBData> sessionUserDB = m_TCPSession->GetLink<SessionUserDBData>(EDBTable::USER);
	size_t deleteCharIndex = sessionUserDB->CheckNickName(m_packet->NickName);
	if (-1 == deleteCharIndex)
	{
		ServerDebug::LogInfo("nickname Fail");
		NetQueue::EnQueue(std::bind(&DeleteCharacterPacketHandler::NetThreadSendResult, std::dynamic_pointer_cast<DeleteCharacterPacketHandler>(shared_from_this())));
		return;
	}

	// ��� ĳ���� ���� ó�� ��û
	CharacterTable_DeleteCharacter deleteQuery = CharacterTable_DeleteCharacter((int)deleteCharIndex);
	if (false == deleteQuery.DoQuery())
	{
		ServerDebug::LogInfo("Fail InsertQuery");
		NetQueue::EnQueue(std::bind(&DeleteCharacterPacketHandler::NetThreadSendResult, std::dynamic_pointer_cast<DeleteCharacterPacketHandler>(shared_from_this())));
		return;
	}
	ServerDebug::LogInfo("Delete OK");
	m_resultPacket.ResultCode = EResultCode::OK;
	
	// ĳ���� ���� �Ϸ� �� ������ ������ ����ȭ
	sessionUserDB->DeleteCharacter(m_packet->NickName);
	NetQueue::EnQueue(std::bind(&DeleteCharacterPacketHandler::NetThreadSendResult, std::dynamic_pointer_cast<DeleteCharacterPacketHandler>(shared_from_this())));
}

void DeleteCharacterPacketHandler::NetThreadSendResult()
{
	ServerSerializer sr;
	m_resultPacket >> sr;
	m_TCPSession->Send(sr.GetBuffer());

	ServerDebug::LogInfo("Send Delete Charater Result");
}


void DeleteCharacterPacketHandler::Start()
{
	ServerDebug::LogInfo("Delete Character Packet");

	std::string nickName; ServerString::UTF8ToANSI(m_packet->NickName, nickName);
	ServerDebug::LogInfo(std::string("Delete NickName: ") + nickName);

	// DB�� ó�� ��û
	m_resultPacket.ResultCode = EResultCode::FAIL;
	DBQueue::EnQueue(std::bind(&DeleteCharacterPacketHandler::DBThreadWork, std::dynamic_pointer_cast<DeleteCharacterPacketHandler>(shared_from_this())));
}
