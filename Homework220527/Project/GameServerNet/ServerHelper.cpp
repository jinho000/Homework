#include "pch.h"
#include "ServerHelper.h"
#include "GameServerBase/ServerDebug.h"

bool ServerHelper::InitSocketLib()
{
	static bool libSetUpCheck = false;
	if (false == libSetUpCheck)
	{
		WSAData wsData;
		int errorCode = WSAStartup(MAKEWORD(2, 2), &wsData);
		if (SOCKET_ERROR == errorCode)
		{
			ServerDebug::LogError("socket lib error");
			return false;
		}

		libSetUpCheck = true;
	}

	return true;
}

std::string ServerHelper::GetMyIP()
{
	InitSocketLib();

    char hostName[255] = {};

    // �����Ұ�� 0 ��ȯ, ���н� -1 (SOCKET_ERROR )��ȯ
    
    if (0 != gethostname(hostName, 255))
    {
        ServerDebug::AssertDebugMsg("Host Name Error");
        return std::string();
    }

    // ���н� nullptr
    HOSTENT* hostInfo = gethostbyname(hostName);
    if (nullptr == hostInfo)
    {
        ServerDebug::AssertDebugMsg("HostInfo Error");
        return std::string();
    }

    // IP �ּҰ� ��������
    IN_ADDR sinAddr = {};

    // IPv4 �ּ�ü�踸 ���
    if (AF_INET != hostInfo->h_addrtype)
    {
        ServerDebug::AssertDebugMsg("Address Family Error");
        return std::string();
    }

    // ��ó�� IP�� ���������Ƿ� ���
    std::string myIP;
    if (0 != hostInfo->h_addr_list[0])
    {
        memcpy(&sinAddr, hostInfo->h_addr_list[0], hostInfo->h_length);//�޸� ����
        myIP = (inet_ntoa(sinAddr));
    }

	return myIP;
}

