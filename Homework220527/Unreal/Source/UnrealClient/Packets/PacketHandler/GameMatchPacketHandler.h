#pragma once
#include "PacketHandlerBase/PacketHandlerBase.h"
// �뵵 :
// �з� :
// ÷�� :
class GameMatchPacketHandler : public PacketHandlerBase<GameMatchPacket>
{
public:
	void Start() override;
};

