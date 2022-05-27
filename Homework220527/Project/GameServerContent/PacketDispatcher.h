#pragma once
#include "ServerPacketBase.h"
#include "PacketHeader.h"
#include "PacketConvertor.h"
#include "PacketHandlerHeader.h"

template <class Session>
using PacketHandler = std::function<void(std::shared_ptr<Session>, std::shared_ptr<ServerPacketBase>)>;

// �� ��Ŷ���� Ÿ���� ����
// ��Ŷ Ÿ�Կ� ���� � �Լ��� ó������ ���������
// ���� ��Ŷ ó���� ���� �ڵ鷯�� �ϳ��� ��� ���� ������
//

// Handler dispacher
template <class Session>
class PacketDispatcher
{
private: // member var
	std::unordered_map<PacketType, PacketHandler<Session>> m_handlers;

public:
	PacketDispatcher();

public: // member Func
	void AddHandler(PacketType _packetType, const PacketHandler<Session>& _handler)
	{
		m_handlers.insert(std::make_pair(_packetType, _handler));
	}

	const PacketHandler<Session>& GetHandler(PacketType _packetType)
	{
		auto iter = m_handlers.find(_packetType);

		// ��Ŷ�� ���� �ڵ鷯�� ��ϵǾ� �־����
		assert(iter != m_handlers.end());

		return iter->second;
	}

	void Dispatch(const std::vector<unsigned char>& _recBuffer, PtrSTCPSession _TCPSession)
	{
		// TCP������ ũ�� Ȯ�� �� ��ȯ�ϱ�

		PacketConvertor convert(_recBuffer);
		const PacketHandler<TCPSession>& handler = GetHandler(convert.GetPacketType());
		handler(_TCPSession, convert.GetPacket());
	}

	template<class PacketType, class PacketHandler>
	static void ProcessHandler(PtrSTCPSession _session, std::shared_ptr<ServerPacketBase> _packet)
	{
		// ��Ŷ ��ȯ
		std::shared_ptr<PacketType> packet = std::dynamic_pointer_cast<PacketType> (_packet);
		assert(nullptr != packet);

		// handler ó�� ����
		std::shared_ptr<PacketHandler> handler = std::make_shared<PacketHandler>();
		handler->Init(_session, packet);
		handler->Start();
	}
};

#include "RegistHandlerToDispatcher.h"
