#include "pch.h"
#include "ChatMessagePacketHandler.h"
#include "GameServerBase/ServerDebug.h"
#include "GameServerBase/ServerString.h"
#include "GameServerNet/TCPSession.h"
#include "GameServerNet/TCPListener.h"
#include <GameServerCore/DBQueue.h>
#include <GameServerCore/NetQueue.h>
#include "SessionUserDBData.h"
#include "DBTableEHeader.h"
#include "ChattingTable.h"

void ChatMessagePacketHandler::DBThreadCheckDB()
{
	ServerDebug::LogInfo("DB work");

	// �г��� ����
	// ������ ������ �ִ� �г��Ӱ� ��ġ�ϴ��� �˻�
	std::shared_ptr<SessionUserDBData> sessionUserDB = m_TCPSession->GetLink<SessionUserDBData>(EDBTable::USER);
	size_t deleteCharIndex = sessionUserDB->CheckNickName(m_packet->NickName);
	if (-1 == deleteCharIndex)
	{
		ServerDebug::LogInfo("Check Chat Nickname Fail");
		return;
	}
	ServerDebug::LogInfo("Check Chat Nickname OK");

	// ��� �ֱ�
	// ������ ���������� ������ ID, nickname, message�� �޾� ��� �ֱ�
	FCharacterInfo characterInfo = sessionUserDB->GetCharacter(m_packet->NickName);
	ChattingTable_InsertChatting insertChatQuery(characterInfo.UserIndex, characterInfo.NickName, m_packet->Message);
	if (false == insertChatQuery.DoQuery())
	{
		ServerDebug::LogInfo("Insert Message Fail");
		return;
	}
	ServerDebug::LogInfo("insert DB OK");

	NetQueue::EnQueue(std::bind(&ChatMessagePacketHandler::NetThreadSendResult, std::dynamic_pointer_cast<ChatMessagePacketHandler>(shared_from_this())));
}

void ChatMessagePacketHandler::NetThreadSendResult()
{
	// ��ε�ĳ����
	// ä�ø޼�����Ŷ�� UTF8�� �޾� �״�� ����
	ServerSerializer sr;
	(*m_packet) >> sr;

	// ����� ��� ���ǿ� ��Ŷ����
	m_TCPSession->GetParent<TCPListener>()->BroadCast(sr.GetBuffer());
}

void ChatMessagePacketHandler::Start()
{
	ServerDebug::LogInfo("ChatMessage Packet");

	std::string nickName;
	std::string message;
	ServerString::UTF8ToANSI(m_packet->NickName, nickName);
	ServerString::UTF8ToANSI(m_packet->Message, message);

	ServerDebug::LogInfo("User NickName: " + nickName);
	ServerDebug::LogInfo("Message: " + message);

	// DBQueue ����
	DBQueue::EnQueue(std::bind(&ChatMessagePacketHandler::DBThreadCheckDB, std::dynamic_pointer_cast<ChatMessagePacketHandler>(shared_from_this())));
}

