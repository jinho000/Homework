#pragma once
#include "PacketHandlerBase/PacketHandlerBase.h"


// �뵵 :
// �з� :
// ÷�� :
class SelectCharacterResultPacketHandler : public PacketHandlerBase<SelectCharacterResultPacket>
{
public: // member Func
	void Start() override;
};

