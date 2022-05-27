#pragma once
#include "ServerNameBase.h"
#include "ServerIOCPWorker.h"
#include "ServerIOCP.h"

// ���� �Ͻ�Ű�� �� job
//struct PostJob : public std::enable_shared_from_this<PostJob>
//{
//	std::function<void()> task_;
//};

// �� ������°���? ����ü�� ������� �ǹ̰� �˴ϴ�.

// �񵿱� ��������¿� job
//struct OverlappedJob : public std::enable_shared_from_this<PostJob>
//{
//	// BOOL ���� ����
//	// DWORD ���� ��Ŷ�̳� ó���� �������� ����
//	// LPOVERLAPPED �񵿱� ������� ������ ��� �ִ� OVERLAPPED�� ������
//	std::function<void(BOOL _Result, DWORD _NumberOfBytes, LPOVERLAPPED)> task_;
//
//
//public:
//	OverlappedJob() {
//
//	}
//
//	~OverlappedJob()
//	{
//		int a = 0;
//	}
//};

// IOCP�� ���� ���� ��Ű�� ���� Ŭ����
// ���ο� ������ Ǯ�� ������ Enqueue�� ���� �۾��� �����ϱ⸸ �ϸ� �ȴ�(������ �Һ��� ����)
class ServerQueue : public ServerNameBase
{
private:
	// ���� �Ͻ�Ű�� �� job
	struct PostWork : public std::enable_shared_from_this<PostWork>
	{
		std::function<void()> work;
	};

private:
	// thread pool���� ����� �Լ�
	void WorkThread(std::shared_ptr<ServerIOCPWorker> _worker, const std::string& _threadName);

	// thread local�� 
	template<typename LocalDataType>
	void WorkThreadLocal(std::shared_ptr<ServerIOCPWorker> _worker, const std::string& _Name, std::function<void(LocalDataType*)> _initLocal)
	{
		if (nullptr == this)
		{
			ServerDebug::AssertDebugMsg("ť ������ ������ �����߽��ϴ�.");
		}

		// ������ �̸� ����
		ServerThread::SetThreadName(_Name + " " + std::to_string(_worker->GetIndex()));

		// thread local ������ �ʿ��� ������ ����
		LocalDataType* threadLocalData = ServerThread::CreateThreadLocalData<LocalDataType>();

		// init local data
		if (nullptr != _initLocal)
		{
			_initLocal(threadLocalData);
		}

		this->RunThread(_worker);

		// thread local ������ ����
		ServerThread::DeleteThreadLocalData<LocalDataType>();
	}

public: // type
	//enum class WORK_TYPE : char
	//{
	//	Default,	// ����Ʈť ��� Ÿ��
	//	Extension	// GetQueuedCompletionStatusEx�� ������ ��� Ÿ��
	//};

	enum class WORK_MSG
	{
		PostWork = -2,
		WORK_DESTROY = -1,	
	};

private: // member var
	ServerIOCP m_Iocp;

public: // default
	ServerQueue();
	~ServerQueue();

	ServerQueue(const ServerQueue& _other) = delete;
	ServerQueue(ServerQueue&& _other) = delete;
	ServerQueue& operator=(const ServerQueue& _other) = delete;
	ServerQueue& operator=(const ServerQueue&& _other) = delete;

private:
	void RunThread(std::shared_ptr<ServerIOCPWorker> _worker);

public: // member Func

	// queue �ʱ�ȭ
	void Initialize(int threadCount, const std::string& _ThreadName = "WorkThread");

	// thread local ���
	template<typename LocalDataType>
	void InitializeLocalData(int threadCount, const std::string& _ThreadName, std::function<void(LocalDataType*)> _initLocal = nullptr)
	{
		m_Iocp.InitializeLocalData<LocalDataType>(std::bind(&ServerQueue::WorkThreadLocal<LocalDataType>, this, std::placeholders::_1, _ThreadName, _initLocal), INFINITE, threadCount);
	}

	// ������ ����
	void Destroy();

	// queue�� �۾� �߰�
	void Enqueue(const std::function<void()>& _work);


	// _socket: ����� ����
	// _onIOCallback: ���Ͽ� IO�̺�Ʈ�� �Ͼ��� ȣ��� �Լ�
	bool RegistSocket(SOCKET _socket, const std::function<void(BOOL, DWORD, LPOVERLAPPED)>* _onIOCallback) const;

};

