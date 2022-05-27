#pragma once
#include "ClientPackets/ServerPacketBase.h"

// �𸮾󿡼� ����ϱ� ���� ���
#include <memory>
#include <vector>

// ����ȭ�Ǿ� ���޵� �����͸� ��Ŷ���� ��ȯ
class PacketConvertor
{
private: // member var
	std::shared_ptr<ServerPacketBase> m_packet;

public: // default
	PacketConvertor() = delete;
	PacketConvertor(const std::vector<uint8_t>& _buffer);
	~PacketConvertor() = default;

	PacketConvertor(const PacketConvertor& _other) = delete;
	PacketConvertor(PacketConvertor&& _other) = delete;

protected:
	PacketConvertor& operator=(const PacketConvertor& _other) = delete;
	PacketConvertor& operator=(const PacketConvertor&& _other) = delete;

private:

public: // member Func
	std::shared_ptr<ServerPacketBase> GetPacket() { return m_packet; }

	template<class PacketType>
	std::shared_ptr<PacketType> GetPacket()
	{ 
		std::shared_ptr<PacketType> packet = std::dynamic_pointer_cast<PacketType>(m_packet);
		assert(nullptr != packet);

		return packet;
	}

	PacketType GetPacketType() { return m_packet->GetPacketType(); }
};

