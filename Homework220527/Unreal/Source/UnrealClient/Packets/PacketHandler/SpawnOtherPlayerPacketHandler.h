#pragma once
#include "PacketHandlerBase/PacketHandlerBase.h"

// �α��� ��� ��Ŷ�� ó���ϱ� ���� �ڵ鷯
class SpawnOtherPlayerPacketHandler : public PacketHandlerBase<SpawnOtherPlayerPacket>
{
public: // member Func
	void Start() override;
};

