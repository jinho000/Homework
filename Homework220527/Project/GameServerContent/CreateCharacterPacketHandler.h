#pragma once
#include <GameServerContent/ServerAndClient.h>
#include "PacketHandlerBase.h"
// �뵵 :
// �з� :
// ÷�� :
class CreateCharacterPacketHandler : public PacketHandlerBase<CreateCharacterPacket>
{
private: // member var
	CreateCharacterResultPacket m_resultPacket;

private:
	void DBThreadWork();
	void NetThreadSendResult();

public: // member Func
	void Start();
};

