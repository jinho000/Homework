#pragma once
#include "IPAddress.h"
#include "EndPoint.h"

// �뵵 : ������ �ּҰ��� ��Ʈ�� ó���ϴ� Ŭ����
// �з� : 
// ÷�� : 
class SocketAddress;
class IPEndPoint : public EndPoint
{
private: // member var
	IPAddress	m_ipAddress;
	int			m_port;

public: // default
	IPEndPoint();
	IPEndPoint(const IPAddress& _ipAddress, int _port);
	IPEndPoint(__int64 address, int port);
	IPEndPoint(const std::string& _ip, int _port);
	
	IPEndPoint(const IPEndPoint& _other);
	IPEndPoint(IPEndPoint&& _other) noexcept;

	IPEndPoint& operator=(const IPEndPoint& _other);
	IPEndPoint& operator=(const IPEndPoint&& _other) noexcept;
	bool operator==(const IPEndPoint& _endPoint) const;
	bool operator!=(const IPEndPoint& _endPoint) const;

	~IPEndPoint();

private:


public: // member Func
	const IPAddress& GetIPAddress() const;
	int GetPort() const;

	AddressFamily GetAddressFamily() const override;
	SocketAddress Serialize() const override;
	uint64_t GetHashCode() const override;

};
