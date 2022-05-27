#include "UnrealThread.h"
#include <vector>
#include <Sockets.h>
#include "../Packets/PacketConvertor.h"

UnrealThread::UnrealThread(FSocket* _socket, TQueue<std::shared_ptr<ServerPacketBase>>* _recvQueue)
	: m_recvSocket(_socket)
	, m_pRecvQueue(_recvQueue)
	, m_bAppClose(true)
{
	if (nullptr == m_recvSocket)
	{
		UE_LOG(LogTemp, Error, TEXT("RecvSocket Error"));
	}
}

UnrealThread::~UnrealThread()
{
}

uint32 UnrealThread::Run()
{
	// ���ú� ó�� ����
	UE_LOG(LogTemp, Log, TEXT("Recv Start"));

	while (m_bAppClose)
	{
		// Recv ���� �Լ��� ó��
		std::vector<uint8_t> recvBuffer;
		recvBuffer.resize(1024);
		int readBytes = 0;
		if (false == m_recvSocket->Recv(&recvBuffer[0], recvBuffer.size(), readBytes))
		{
			break;
		}

		UE_LOG(LogTemp, Log, TEXT("Recv data"));

		// ���޹��� ��Ŷ�� ���ú� ť�� �߰�
		// ���ú� ť�� �� ���Ӹ�忡 �޸� ��Ŷ ������Ʈ ƽ���� ó��
		PacketConvertor convertor(recvBuffer);

		check(nullptr != convertor.GetPacket());

		m_pRecvQueue->Enqueue(convertor.GetPacket());
	}

	return 0;
}

void UnrealThread::Stop()
{
	m_bAppClose = false;
}

void UnrealThread::Exit()
{
}
