#pragma once
#include <GameServerBase/ServerQueue.h>

// ��Ʈ��ũ�󿡼� ����ϴ� ���� ó��
class NetQueue
{
private: // Member Function
	static ServerQueue WorkQueue;

private: // default
	NetQueue() = default;
	~NetQueue() = default;

	NetQueue(const NetQueue& _other) = delete;
	NetQueue(NetQueue&& _other) = delete;
	NetQueue& operator=(const NetQueue& _other) = delete;
	NetQueue& operator=(const NetQueue&& _other) = delete;


public: // member Func
	static void Init();
	static void Destroy();
	static void EnQueue(const std::function<void()>& _work);

	static const ServerQueue& GetQueue() { return WorkQueue; }
};

