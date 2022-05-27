#pragma once

// �뵵 : ������ �ּҰ� + ��Ʈ ����ȭ ó�� Ŭ����
// �з� :
// ÷�� :
class IPEndPoint;
class IPAddress;
class SocketAddress
{
private: // member var
	char* m_pBuffer;
	size_t m_BufferMaxSize;
	size_t m_BufferLength;

private:
	void Initialize();
	void Destroy();

public: // default
	SocketAddress() = delete;

	SocketAddress(const IPAddress& _ipAddress, int port);
	SocketAddress(const IPEndPoint& _ipEndPoint);

	SocketAddress(const SocketAddress& _other);
	SocketAddress(SocketAddress&& _other) noexcept;

	SocketAddress& operator=(const SocketAddress& _other);
	SocketAddress& operator=(SocketAddress&& _other) noexcept;

	~SocketAddress();


private:

public: // member Func
	const char* GetBuffer() const;
	size_t GetBufferLength() const;

	AddressFamily GetAddressFamily() const;
	int GetPort() const;

	IPAddress GetIPAddress() const;
	IPEndPoint GetIPEndPoint() const;
};

