#pragma once
#include "PacketHandlerBase.h"
#include "UserTable.h"

// �α��� ��Ŷó�� �Լ� Ŭ����
// �α��� ���� ó���� �Լ��� �ϳ��� Ŭ������ ��� ����
class LoginPacketHandler : public PacketHandlerBase<LoginPacket>
{
private:
	LoginResultPacket			m_loginResultPacket;
	CharacterListPacket			m_CharacterListPacket;
	std::shared_ptr<UserRow>	m_userData;

private:
	void DBThreadCheckLogin();			// �α��� ��� üũ
	void NetThreadSendLoginResult();	// �α��� ��� ����
	void DBThreadCheckCharList();		// ������ ĳ���� ���� ��������
	void NetThreadSendCharList();		// ������ ĳ���� ���� ����

public: // member Func
	void Start();

};

