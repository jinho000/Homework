#pragma once
#include "PacketHandlerBase/PacketHandlerBase.h"

// �α��� ��� ��Ŷ�� ó���ϱ� ���� �ڵ鷯
class ChatMessagePacketHandler : public PacketHandlerBase<ChatMessagePacket>
{
public: // member Func
	void Start() override;
};

