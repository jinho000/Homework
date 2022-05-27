// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"

#include <vector>
#include <memory>
#include <Interfaces/IPv4/IPv4Endpoint.h>

#include "../Packets/ClientPackets/ServerPacketBase.h"
#include "UnrealThread.h"
#include "UnrealUDPThread.h"
#include "CGameInstance.generated.h"

class UCChatWindow;


// ���� ���ۺ��� ����ñ��� ����ִ� Ŭ����
// ������ �ٲ𶧿��� ���� ������ ó��
UCLASS()
class UNREALCLIENT_API UCGameInstance : public UGameInstance
{
	GENERATED_BODY()

private:
	// Socket
	TQueue<std::shared_ptr<ServerPacketBase>> m_packetQueue;

	UnrealThread* m_recvThread;
	FRunnableThread* m_runnableThread;

	UnrealUDPThread* m_UDPRecvThread;
	FRunnableThread* m_UDPrunnableThread;

	ISocketSubsystem* m_socketSystem;
	FSocket* m_socket;
	FSocket* m_UDPsocket;

	// Server Info
	FString				m_serverIP;			// TCP, UDP �������� ���
	int					m_TCPServerPort;

	int					m_UDPServerPort;
	int					m_unrealUDPPort;

	FIPv4Endpoint		m_serverUDPEndPoint;

	// Chatting
	UCChatWindow* m_chatWindow;

	// Play
	uint64_t m_playerID;
	int m_sessionIdx;
	int m_playerIdx;
	std::vector<uint64_t> m_otherPlayerID;
public:
	// Login
	TAtomic<bool>		LoginProcess;
	class UCLoginUI* LoginUI;

	// Join
	class UJoinUI* JoinUI;

	// User
	std::vector<FCharacterInfo> UserCharacterList;
	FCharacterInfo				SelectCharacter;

	// Chracter Select UI
	class UCharacterSelectUI* CharacterSelectUI;
	class UListView* CharacterSelectUIListView;

	// default
public:
	UCGameInstance();
	virtual ~UCGameInstance();

	// Socket
private:
	void CloseSocket();


	// Server
public:
	// ���� ���� �Լ�
	bool ConnectServer(const FString& _IP, const FString& _port);
	bool ConnectUDPServer();
	void StartUDPThread(); 
	void EndUPDThread();

	bool SendBytes(const std::vector<uint8>& _packet);
	bool SendUDP(const std::vector<uint8>& _packet);

	// ����� ������ ������ ���� �Լ�(�𸮾��� ���ڿ����� UTF16)
	// ������ Ŭ���̾�Ʈ�� ���ڿ� ������ �ٸ��� ������ �ϳ��� �����ؾ���
	// -> UTF8 �������� ����
	//    ���۽� utf8�� ��ȯ�Ͽ� ����, ���Ž� utf8�� ��ȯ�Ͽ� ����
	//bool SendFString(const FString& _fstr);

	TQueue<std::shared_ptr<ServerPacketBase>>& GetPacketQueue() { return m_packetQueue; }

	// Server Packet �׽�Ʈ�Լ�
	void AddServerPacket(std::shared_ptr<ServerPacketBase> _serverPacket);

	// ���� UDP��Ʈ ����
	void SetUDPEndPoint(int serverUDPPort);

	// �𸮾� UDP��Ʈ 
	int GetUnrealUDPPort() { return m_unrealUDPPort; }

	// Chatting
public:

	UCChatWindow* GetChatWindow()
	{
		check(nullptr != m_chatWindow)
			return m_chatWindow;
	}

	void SetChatWindow(UCChatWindow* _chatWindow) { m_chatWindow = _chatWindow; }

	// Characte
public:
	void DeleteCharacter(const std::string& _deleteNickName);


	// Play
public:
	void SetPlayerID(uint64_t playerID);
	void SetSessionIdx(int sessionIdx);
	void SetPlayerIdx(int playerIdx);
	void SetOtherPlayerID(const std::vector<uint64_t>& otherPlayerID);

	uint64_t GetPlayerID();
	int GetSessionIdx();
	int GetPlayerIdx();
	const std::vector<uint64_t>& GetOtherPlayerID();
};
