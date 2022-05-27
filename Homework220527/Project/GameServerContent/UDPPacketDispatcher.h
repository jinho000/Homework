#pragma once
#include "PacketType.h"
#include "ServerPacketBase.h"
#include "PacketConvertor.h"

// �뵵 :
// �з� :
// ÷�� :
class UDPPacketDispatcher
{
	using PacketHandler = std::function<void(std::shared_ptr<UDPSession>, std::shared_ptr<ServerPacketBase>, const IPEndPoint&)>;

private: // member var
	std::unordered_map<PacketType, PacketHandler> m_handlers;

public: // default
	UDPPacketDispatcher();
	~UDPPacketDispatcher();

	UDPPacketDispatcher(const UDPPacketDispatcher& _other) = delete;
	UDPPacketDispatcher(UDPPacketDispatcher&& _other) = delete;
	UDPPacketDispatcher& operator=(const UDPPacketDispatcher& _other) = delete;
	UDPPacketDispatcher& operator=(const UDPPacketDispatcher&& _other) = delete;

private: // member Func
	void AddHandler(PacketType _packetType, const PacketHandler& _handler)
	{
		m_handlers.insert(std::make_pair(_packetType, _handler));
	}

	void RegistHandler();

public:
	void Dispatch(const std::vector<unsigned char>& _recBuffer, PtrSUDPSession _UDPSession, const IPEndPoint& _clientEndPoint)
	{
		// UDP�� �����Ͱ� �ѹ��� ��
		PacketConvertor convert(_recBuffer);
		auto iter = m_handlers.find(convert.GetPacketType());
		assert(iter != m_handlers.end());

		const PacketHandler& handler = iter->second;
		handler(_UDPSession, convert.GetPacket(), _clientEndPoint);
	}

	template<class PacketType, class PacketHandler>
	static void ProcessHandler(PtrSUDPSession _session, std::shared_ptr<ServerPacketBase> _packet, const IPEndPoint& _endPoint)
	{
		// ��Ŷ ��ȯ
		std::shared_ptr<PacketType> packet = std::dynamic_pointer_cast<PacketType> (_packet);
		assert(nullptr != packet);

		// handler ó�� ����
		std::shared_ptr<PacketHandler> handler = std::make_shared<PacketHandler>();
		handler->InitUDP(_session, packet, _endPoint);
		handler->Start();
	}
};

