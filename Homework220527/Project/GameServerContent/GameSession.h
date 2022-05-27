#pragma once
#include "ServerStruct.h"

// ������ ������ ����
class ServerPacketBase;
class GameSession
{
	friend class ContentManager;
private: // member var
	std::mutex				m_userInfoLock;
	std::vector<UserInfo>	m_userInfo;		// session�� ����ִ� ������ ����
	size_t					m_sessionIdx;	// session�� �ε��� ��ȣ

public: // default
	GameSession(UINT userCount, size_t sessionIdx);
	~GameSession();

	// (contentmanager vector)
	GameSession(const GameSession& other);
	GameSession(GameSession&& other) noexcept;
	GameSession& operator=(const GameSession& other);
	GameSession& operator=(GameSession&& other) noexcept;

private:
	// ContentManger���� ���� �ɰ� �����ϴ� �Լ�

	// ���� �߰�
	void AddUser(const UserInfo& userInfo);
	
	// Ŭ���̾�Ʈ���� matching packet ����
	void BroadCastMachingPacket();

	// �÷��̾� ������ ����
	void SetPlayerData(const FPlayerUpdateData& playerData);

public: // member Func
	void BroadCastTCP(const std::shared_ptr<ServerPacketBase>& packet);
	void BroadCastUDP(const std::shared_ptr<ServerPacketBase>& packet, const std::shared_ptr<UDPSession>& udpSession);

	void BroadCastUDPPlayerData(const FPlayerUpdateData& playerData, const std::shared_ptr<UDPSession>& udpSession);
};

