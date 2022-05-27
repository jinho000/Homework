#include "pch.h"
#include "ServerSectionThread.h"
#include <GameServerBase/ServerQueue.h>

ServerSectionThread::ServerSectionThread()
{
}

ServerSectionThread::~ServerSectionThread()
{
}

// ���� ������ �Լ�
void ServerSectionThread::SectionThreadWork(UINT _threadOrder)
{
	SetThreadName(GetNameCopy());
	SetThreadOrder(_threadOrder);
	IOCP.InitHandle(1);

	bool isExit = false;
	while (isExit == false)
	{
		// �����忡 �������� ó��
		while (true)
		{
			// ���� �̹� IOCP�� ������ �ְ�.
			DWORD NumberOfBytesTransferred;
			ULONG_PTR CompletionKey;
			LPOVERLAPPED lpOverlapped;

			// POST�Ȱ� ������ ���ش�.
			BOOL Result = IOCP.Execute(NumberOfBytesTransferred, CompletionKey, lpOverlapped, 1);

			// ���� ������ �ִٴ� �ǵ�.
			if (FALSE == Result)
			{
				if (WAIT_TIMEOUT == GetLastError())
				{
					break;
				}

				// ���״�� �ƹ��͵� ��� �׳� ���°̴ϴ�.
				// Ÿ�Ӿƿ��̰� ���� ���� ����.
				break;
			}

			int MessageType = static_cast<int>(NumberOfBytesTransferred);
			switch (MessageType)
			{
			case -1:
				// ����
				isExit = true;
				break;
			default:
				if (0 != CompletionKey)
				{
					//PostJob* JobTesk = reinterpret_cast<PostJob*>(CompletionKey);
					//JobTesk->task_();
				}
				break;
			}

			if (isExit)
			{
				break;
			}
		}

		// Thread���� Ÿ�̸Ӹ� ������ ����ȭ ������ �ð� ������ ���ؼ� �Ű澲�� ������ �ִ�.
		float DelataTime = Timer.Update();
		for (size_t i = 0; i < m_allSection.size(); i++)
		{
			// �̰� ��������
			//m_allSection[i]->AccTimeUpdate(DelataTime);
			m_allSection[i]->Update(DelataTime);
			m_allSection[i]->Release();
		}


		if (m_insertSection.empty() == false)
		{
			// ������ ������ �ٸ� ������ �߰��Ǹ� ���⼭ �����ɰ� �߰��Ѵ�
			std::lock_guard lock(m_insertLock);
			for (const std::shared_ptr<ServerSection>& section : m_insertSection)
			{
				m_allSection.push_back(section);
			}

			m_insertSection.clear();
		}

		Sleep(1);
	}
}

void ServerSectionThread::AddSection(const std::shared_ptr<ServerSection>& _section)
{
	// �����忡�� ���° �������� ����
	_section->SetSectionIndex(static_cast<UINT>(m_allSection.size()));
	m_insertSection.push_back(_section);
}

void ServerSectionThread::StartThread(UINT _threadOrder)
{
	Start(std::bind(&ServerSectionThread::SectionThreadWork, this, _threadOrder));
}

void ServerSectionThread::Destroy()
{
	IOCP.PostQueued(static_cast<DWORD>(ServerQueue::WORK_MSG::WORK_DESTROY), 0);
	Sleep(1);
}
