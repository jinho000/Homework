#pragma once
#include "PacketHandlerBase/PacketHandlerBase.h"

// �α��� ��� ��Ŷ�� ó���ϱ� ���� �ڵ鷯
class LoginResultPacketHandler : public PacketHandlerBase<LoginResultPacket>
{
public: // member Func
	void Start() override;
};

