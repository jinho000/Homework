#include <iostream>
#include <WinSock2.h>
#include <Windows.h>
#include <WS2tcpip.h> // inet_pton 함수 헤더
#include <conio.h>

#pragma comment(lib, "ws2_32") 
#include <thread>

std::thread RecvThread;

bool Check = true;

void RecvFunc(SOCKET _SessionSocket)
{
	std::string recvBuff;
	recvBuff.reserve(1024);

	while (Check)
	{
		char Buffer[1024] = { 0, };
		int Result = recv(_SessionSocket, Buffer, sizeof(Buffer), 0);

		if (SOCKET_ERROR == Result)
		{
			return;
		}
		std::string stdBuffer = Buffer;
		recvBuff += Buffer;

		std::cout << "Buffer: " << Buffer << std::endl;

		if (std::string::npos != recvBuff.find("!!"))
		{
			std::cout << "Recv: " << recvBuff << std::endl;
		}
	}
}

int main()
{
	WSADATA wsa;

	if (0 != WSAStartup(MAKEWORD(2, 2), &wsa))
	{
		std::cout << "WSAStartup Error" << std::endl;
	}

	SOCKET SessionSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (INVALID_SOCKET == SessionSocket)
	{
		return 0;
	}

	std::cout << "IP주소" << std::endl;
	std::string Ip;
	std::string Port;
	std::cin >> Ip;

	if ("Q" == Ip
		|| "q" == Ip)
	{
		Ip = "58.150.30.210";
	}

	SOCKADDR_IN Add = { 0, };
	Add.sin_family = AF_INET;
	Add.sin_port = htons(30001);
	if (SOCKET_ERROR == inet_pton(AF_INET, Ip.c_str(), &Add.sin_addr))
	{
		return 0;
	}
	int Len = sizeof(SOCKADDR_IN);

	if (SOCKET_ERROR == connect(SessionSocket, (const sockaddr*)&Add, Len))
	{
		return 0;
	}

	std::cout << "커넥트 성공." << std::endl;

	RecvThread = std::thread(RecvFunc, SessionSocket);

	while (true)
	{
		std::string In;


		std::cin >> In;

		if (In == "q" || In == "Q")
		{
			closesocket(SessionSocket);
			Check = false;
			RecvThread.join();
			Sleep(1);
			return 0;
		}

		char Buffer[1024] = { "" };
		Sleep(1);
		memcpy_s(Buffer, sizeof(Buffer), In.c_str(), In.size());

		int Result = send(SessionSocket, Buffer, sizeof(Buffer), 0);
	}

	_getch();
}
