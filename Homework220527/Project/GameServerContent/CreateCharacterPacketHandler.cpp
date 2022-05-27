#include "pch.h"
#include "CreateCharacterPacketHandler.h"
#include <GameServerBase/ServerString.h>
#include <GameServerNet/TCPSession.h>
#include <GameServerCore/DBQueue.h>
#include <GameServerCore/NetQueue.h>
#include "SessionUserDBData.h"
#include "DBTableEHeader.h"
#include "CharacterTable.h"

void CreateCharacterPacketHandler::DBThreadWork()
{
	ServerDebug::LogInfo("Check DB");

	// �ش� �г����� �ִ��� Ȯ��
	CharacterTable_SelectNickName SelectQuery = CharacterTable_SelectNickName(m_packet->NickName);
	if (true == SelectQuery.DoQuery())
	{
		m_resultPacket.ResultCode = ECreateCharacterResultCode::ID_DULE;
		ServerDebug::LogInfo("NickName is already exist");
		NetQueue::EnQueue(std::bind(&CreateCharacterPacketHandler::NetThreadSendResult, std::dynamic_pointer_cast<CreateCharacterPacketHandler>(shared_from_this())));
		return;
	}

	// ��� ĳ���� ���� ó�� ��û
	std::shared_ptr<SessionUserDBData> sessionUserDB = m_TCPSession->GetLink<SessionUserDBData>(EDBTable::USER);
	CharacterTable_CreateCharacter InsertQuery = CharacterTable_CreateCharacter(m_packet->NickName, sessionUserDB->UserInfo->Index);
	if (false == InsertQuery.DoQuery())
	{
		m_resultPacket.ResultCode = ECreateCharacterResultCode::FAIL;
		ServerDebug::LogInfo("Fail InsertQuery");
		NetQueue::EnQueue(std::bind(&CreateCharacterPacketHandler::NetThreadSendResult, std::dynamic_pointer_cast<CreateCharacterPacketHandler>(shared_from_this())));
		return;
	}

	// ������ ĳ���� ���� ��������
	CharacterTable_SelectNickName CharInfoSelectQuery(m_packet->NickName);
	if (false == CharInfoSelectQuery.DoQuery())
	{
		m_resultPacket.ResultCode = ECreateCharacterResultCode::FAIL;
		ServerDebug::LogInfo("Fail Select Query");
		NetQueue::EnQueue(std::bind(&CreateCharacterPacketHandler::NetThreadSendResult, std::dynamic_pointer_cast<CreateCharacterPacketHandler>(shared_from_this())));
		return;
	}
	ServerDebug::LogInfo("Check DB OK");

	m_resultPacket.ResultCode = ECreateCharacterResultCode::OK;
	m_resultPacket.CharacterInfo.Index = CharInfoSelectQuery.RowData->Index;
	m_resultPacket.CharacterInfo.NickName = CharInfoSelectQuery.RowData->NickName;
	m_resultPacket.CharacterInfo.UserIndex = CharInfoSelectQuery.RowData->UserIndex;
	m_resultPacket.CharacterInfo.Att = CharInfoSelectQuery.RowData->Att;
	m_resultPacket.CharacterInfo.Hp = CharInfoSelectQuery.RowData->Hp;
	m_resultPacket.CharacterInfo.LastRoomID = CharInfoSelectQuery.RowData->LastRoomID;
	m_resultPacket.CharacterInfo.RoomX = CharInfoSelectQuery.RowData->RoomX;
	m_resultPacket.CharacterInfo.RoomY = CharInfoSelectQuery.RowData->RoomY;
	m_resultPacket.CharacterInfo.RoomZ = CharInfoSelectQuery.RowData->RoomZ;

	
	// ĳ���� ���� �Ϸ� �� ������ ������ ����ȭ
	sessionUserDB->UserCharacterList.push_back(m_resultPacket.CharacterInfo);

	NetQueue::EnQueue(std::bind(&CreateCharacterPacketHandler::NetThreadSendResult, std::dynamic_pointer_cast<CreateCharacterPacketHandler>(shared_from_this())));
}

void CreateCharacterPacketHandler::NetThreadSendResult()
{
	ServerSerializer sr;
	m_resultPacket >> sr;
	m_TCPSession->Send(sr.GetBuffer());

	ServerDebug::LogInfo("Send Create Charater Result");
}

void CreateCharacterPacketHandler::Start()
{
	ServerDebug::LogInfo("Create Character Packet");

	std::string nickName; ServerString::UTF8ToANSI(m_packet->NickName, nickName);
	ServerDebug::LogInfo(std::string("Character NickName: ") + nickName);
	
	// DB�� ó�� ��û
	m_resultPacket.ResultCode = ECreateCharacterResultCode::FAIL;
	DBQueue::EnQueue(std::bind(&CreateCharacterPacketHandler::DBThreadWork, std::dynamic_pointer_cast<CreateCharacterPacketHandler>(shared_from_this())));
}
