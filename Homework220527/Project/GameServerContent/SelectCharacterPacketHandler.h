#pragma once
#include "PacketHandlerBase.h"

// �뵵 :
// �з� :
// ÷�� :
class SelectCharacterPacketHandler : public PacketHandlerBase<SelectCharacterPacket>
{
private:
	SelectCharacterResultPacket m_resultPacket;
	FCharacterInfo				m_selectCharacter;

private:
	void DBThreadCheckSelectCharacter();	// ������ ĳ���� ���üũ
	void NetThreadSendSelectResult();		// ��� ����
	void InsertUserToSection();

public: // member Func
	void Start() override;
};

