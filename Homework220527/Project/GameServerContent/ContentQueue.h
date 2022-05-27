#pragma once

// ������ �������� ���õ� ���� ó��
class ContentQueue
{
private: // Member Function
	static ServerQueue WorkQueue;

public: // default
	ContentQueue() = default;
	~ContentQueue() = default;

	ContentQueue(const ContentQueue& _other) = delete;
	ContentQueue(ContentQueue&& _other) = delete;
	ContentQueue& operator=(const ContentQueue& _other) = delete;
	ContentQueue& operator=(const ContentQueue&& _other) = delete;

public: // member Func
	static void Init();
	static void Destroy();
	static void EnQueue(const std::function<void()>& _work);
};
