#pragma once
#include "PacketHeader.h"


// ��Ŷ�� ó���� �ڵ鷯�� �⺻ �θ� Ŭ����
template<class PacketType>
class PacketHandlerBase : public std::enable_shared_from_this<PacketHandlerBase<PacketType>>
{
protected: // member var
	PtrSTCPSession				m_TCPSession;
	std::shared_ptr<PacketType> m_packet;

public: // member Func
	void Init(PtrSTCPSession _TCPSession, std::shared_ptr<PacketType> _packet);
	virtual void Start() = 0;
};

template<class PacketType>
inline void PacketHandlerBase<PacketType>::Init(PtrSTCPSession _TCPSession, std::shared_ptr<PacketType> _packet)
{
	m_TCPSession = _TCPSession;
	m_packet = _packet;
}
