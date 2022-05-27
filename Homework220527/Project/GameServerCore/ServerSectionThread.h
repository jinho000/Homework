#pragma once
#include <GameServerBase/ServerThread.h>
#include <GameServerBase/ServerIOCP.h>
#include "ServerSection.h"

// �����忡�� ������ ó��
class ServerSectionThread : public ServerThread
{
private: // member var
	std::vector<std::shared_ptr<ServerSection>> m_allSection; // �����忡�� �����ϴ� ����
	
	ServerIOCP IOCP; // thread�� ���� �ޱ� ���� IOCP

	// insert
	// ���� �߰��ÿ��� ���� ����
	// ó���� ���ǰ����� ������ ����� ��� �ʿ����
	std::mutex m_insertLock;
	std::vector<std::shared_ptr<ServerSection>> m_insertSection;

public: // default
	ServerSectionThread();
	~ServerSectionThread();

	ServerSectionThread(const ServerSectionThread& _other) = delete;
	ServerSectionThread(ServerSectionThread&& _other) = delete;
	ServerSectionThread& operator=(const ServerSectionThread& _other) = delete;
	ServerSectionThread& operator=(const ServerSectionThread&& _other) = delete;

private:
	void SectionThreadWork(UINT _threadOrder);

public: // member Func
	void AddSection(const std::shared_ptr<ServerSection>& _section);
	void StartThread(UINT _threadOrder);
	void Destroy();

	void Enqueue();
};

