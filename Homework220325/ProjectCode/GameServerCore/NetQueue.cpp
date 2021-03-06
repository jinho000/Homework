#include "PreCompile.h"
#include "NetQueue.h"

GameServerQueue NetQueue::JobQueue = GameServerQueue();

NetQueue::NetQueue()
{

}

NetQueue::~NetQueue()
{

}


void NetQueue::Init() {
	JobQueue.Initialize(GameServerQueue::WORK_TYPE::Default, 8, "NetThread");
}

void NetQueue::Queue(std::function<void()>& CallBack)
{
	JobQueue.EnQueue(CallBack);
}

void NetQueue::Destroy()
{
	JobQueue.Destroy();
}