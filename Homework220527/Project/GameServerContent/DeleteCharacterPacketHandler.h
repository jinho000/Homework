#pragma once
#include <GameServerContent/ServerAndClient.h>
#include "PacketHandlerBase.h"
// �뵵 :
// �з� :
// ÷�� :
class DeleteCharacterPacketHandler : public PacketHandlerBase<DeleteCharacterPacket>
{
private: // member var
	DeleteCharacterResultPacket m_resultPacket;

private:
	void DBThreadWork();
	void NetThreadSendResult();

public: // member Func
	void Start() override;
};

