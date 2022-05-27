#include "pch.h"
#include "ContentCore.h"
#include <GameServerNet/TCPSession.h>
#include <GameServerCore/ServerSectionManager.h>
#include <GameServerCore/ServerSection.h>
#include <GameServerNet/UDPSession.h>
#include "ContentEnum.h"
#include "ContentManager.h"
#include "ContentQueue.h"


PacketDispatcher<TCPSession>				ContentCore::TcpDispatcher;
UDPPacketDispatcher							ContentCore::UdpDispatcher;

std::mutex									ContentCore::UnserEndPointLock;
std::vector<IPEndPoint>						ContentCore::AllUserEndPoint;

std::mutex									ContentCore::ClientPlayerLock;

std::unordered_map<uint64_t, std::shared_ptr<ClientPlayer>>	ContentCore::AllClientPlayer;

ContentCore::ContentCore()
{
}

ContentCore::~ContentCore()
{
}

void ContentCore::AcceptEvent(std::shared_ptr<TCPSession> _tcpSession)
{
	_tcpSession->SetCallBack(RecvEvent, CloseEvent);

	std::string log = std::to_string(static_cast<int>(_tcpSession->GetSessionSocket()));
	log += " Socket Connected";
	ServerDebug::LogInfo(log);
}

void ContentCore::RecvEvent(std::shared_ptr<TCPSession> _tcpSession, const std::vector<unsigned char>& _recvBuffer)
{
	// Dispatcher������ �����޸𸮿� ���� ��찡 �����Ƿ� ����ȭ���� �ʾƵ� �ȴ�
	TcpDispatcher.Dispatch(_recvBuffer, _tcpSession);
}

void ContentCore::CloseEvent(std::shared_ptr<TCPSession> _tcpSession)
{
	std::string LogText = std::to_string(static_cast<int>(_tcpSession->GetSessionSocket()));
	ServerDebug::LogInfo(LogText + " Socket Disconnected");
}

void ContentCore::UDPRecvEvent(std::shared_ptr<UDPSession> _udpSession, const std::vector<unsigned char>& _recvBuffer, IPEndPoint& _clientEndPoint)
{
	UdpDispatcher.Dispatch(_recvBuffer, _udpSession, _clientEndPoint);
}


void ContentCore::AddNewPlayer(const std::shared_ptr<ClientPlayer>& _clientPlayer)
{
	ClientPlayerLock.lock();
	AllClientPlayer.insert(make_pair(_clientPlayer->GetPlayerID(), _clientPlayer));
	ClientPlayerLock.unlock();
}

void ContentCore::SetPlayerData(const FPlayerUpdateData& _playerUpdateData)
{
	ClientPlayerLock.lock();
	AllClientPlayer.find(_playerUpdateData.PlayerID)->second->SetPlayerData(_playerUpdateData);
	ClientPlayerLock.unlock();
}

const std::unordered_map<uint64_t, std::shared_ptr<ClientPlayer>>& ContentCore::GetAllPlayer()
{
	return AllClientPlayer;
}

void ContentCore::SetUserEndPoint(const IPEndPoint& _userEndPoint)
{
	UnserEndPointLock.lock();
	AllUserEndPoint.push_back(_userEndPoint);
	UnserEndPointLock.unlock();
}

void ContentCore::BroadCastUDP(ServerPacketBase* _packet, UDPSession* _udpSession)
{
	UnserEndPointLock.lock();
	for (const IPEndPoint& userEndPoint : AllUserEndPoint)
	{
		ServerSerializer sr;
		*_packet >> sr;
		_udpSession->Send(sr.GetBuffer(), userEndPoint);
	}
	UnserEndPointLock.unlock();
}

void ContentCore::BroadCastAllPlayerDataUDP(const std::shared_ptr<UDPSession>& _udpSession)
{
	// ��� ������ ������ ��Ŷ�� ����
	AllPlayerInfoPacket packet;
	ClientPlayerLock.lock();
	auto iter = AllClientPlayer.begin();
	while (iter != AllClientPlayer.end())
	{
		packet.AllPlayerInfo.push_back(iter->second->GetPlayerData());
		++iter;
	}
	ClientPlayerLock.unlock();

	// ��Ŷ�� ��ε�ĳ����
	UnserEndPointLock.lock();
	for (const IPEndPoint& userEndPoint : AllUserEndPoint)
	{
		ServerSerializer sr;
		packet >> sr;
		_udpSession->Send(sr.GetBuffer(), userEndPoint);
	}
	UnserEndPointLock.unlock();
}

void ContentCore::UserStart()
{
	// TCP Accept �̺�Ʈ ó��
	SetAcceptCallBack(ContentCore::AcceptEvent);

	// UDP Session ����
	CreateUDPSession(4);
	SetUDPRecvCallBack(ContentCore::UDPRecvEvent);

	// SessionQueue �����
	ContentQueue::Init();

	// ContentManager ó��
	// ������ ������ ���� ������ ó��
	ContentManager::Init();


}

void ContentCore::UserEnd()
{
	ContentManager::Destroy();
	ContentQueue::Destroy();
}
