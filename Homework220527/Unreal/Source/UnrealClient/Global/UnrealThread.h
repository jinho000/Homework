// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include <memory>

#include "../Packets/ClientPackets/ServerPacketBase.h"


//���ú� ó���� �ٸ� �����忡�� ó��
//->���ν����忡�� ó���Ұ��
// ���� ���ú� : ���� ������ ����
// �񵿱� ���ú�ó�� : ���ν����忡�� �̺�Ʈ�� ��� Ȯ��
// 
// recv�� ó���ϱ� ���� ������
class UnrealThread : public FRunnable
{
private:
	FSocket*									m_recvSocket;
	TQueue<std::shared_ptr<ServerPacketBase>>*	m_pRecvQueue;
	TAtomic<bool>								m_bAppClose;

public:
	UnrealThread() = delete;
	UnrealThread(FSocket* _socket, TQueue<std::shared_ptr<ServerPacketBase>>* _recvQueue);
	~UnrealThread();

public:
	uint32 Run() override;
	void Stop() override;
	void Exit() override;
};
