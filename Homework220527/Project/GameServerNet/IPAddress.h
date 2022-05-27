#pragma once

// �뵵 : IP �ּҰ� ó�� Ŭ����
// �з� :
// ÷�� : �ּҰ��� �޾� ��Ʈ��ũ����Ʈ���� ������ ó��
class IPAddress
{
private: // member var
	__int64			m_Address;
	AddressFamily	m_AddressFamily;
	bool			m_bInvalidAddress;

public:
	static IPAddress ParseToIPv4(const std::string& _ip);
	static __int64 ParseToIPv4Int64(const std::string& _ip);

public: // default
	IPAddress() = delete;
	IPAddress(std::string ip);
	IPAddress(__int64 _NetworkByteOrderAddr);
	~IPAddress() = default;

	IPAddress(const IPAddress& _other) noexcept;
	IPAddress(IPAddress&& _other) noexcept;
	IPAddress& operator=(const IPAddress& _other) noexcept;
	IPAddress& operator=(IPAddress&& _other) noexcept;

private:

public: // member func
	__int64 GetAddress() const;
	AddressFamily GetAddressFaimly() const;
	bool IsValidAddress() const;
};

