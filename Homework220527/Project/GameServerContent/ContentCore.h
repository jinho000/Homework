#pragma once
#include <GameServerCore/ServerCore.h>
#include "PacketDispatcher.h"
#include "UDPPacketDispatcher.h"
#include "ClientPlayer.h"
#include "ServerPacketBase.h"

// �뵵 :
// �з� :
// ÷�� :
class ContentCore : public ServerCore
{
private: // member var
	static PacketDispatcher<TCPSession>					TcpDispatcher;
	static UDPPacketDispatcher							UdpDispatcher;
	
	// ���Ǹ���� ������ ���� �ص�����Ʈ�� �ھ ������(���� �����忡�� ���� ���� ����)
	static std::mutex													UnserEndPointLock;
	static std::vector<IPEndPoint>										AllUserEndPoint;

	static std::mutex													ClientPlayerLock;
	static std::unordered_map<uint64_t, std::shared_ptr<ClientPlayer>>	AllClientPlayer;

public:
	ContentCore();
	~ContentCore();

public: // default
	ContentCore(const ContentCore& _other) = delete;
	ContentCore(ContentCore&& _other) = delete;
	ContentCore& operator=(const ContentCore& _other) = delete;
	ContentCore& operator=(const ContentCore&& _other) = delete;

protected:
	static void AcceptEvent(std::shared_ptr<TCPSession> _tcpSession);
	static void RecvEvent(std::shared_ptr<TCPSession> _tcpSession, const std::vector<unsigned char>& _recBuffer);
	static void CloseEvent(std::shared_ptr<TCPSession> _tcpSession);
	static void UDPRecvEvent(std::shared_ptr<UDPSession> _udpSession, const std::vector<unsigned char>& _recvBuffer, IPEndPoint& _clientEndPoint);

public:
	// �������� �ű��
	static void AddNewPlayer(const std::shared_ptr<ClientPlayer>& _clientPlayer);
	static void SetPlayerData(const FPlayerUpdateData& _playerUpdateData);

	static const std::unordered_map<uint64_t, std::shared_ptr<ClientPlayer>>& GetAllPlayer();

	static void SetUserEndPoint(const IPEndPoint& _userEndPoint);
	static const std::vector<IPEndPoint>& GetAllUserEndPoint() { return AllUserEndPoint; };

	static void BroadCastUDP(ServerPacketBase* _packet, UDPSession* _udpSession);
	static void BroadCastAllPlayerDataUDP(const std::shared_ptr<UDPSession>& _udpSession);

public: // member Func
	void UserStart();
	void UserEnd();
};

