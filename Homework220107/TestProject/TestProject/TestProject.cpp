#include <iostream>
#include <string>

bool CheckIP(std::string& _ip, int& port)
{
	std::string ip = _ip;
	int idx = 0;
	int addr[3] = {0, };
	for (int i = 0; i < 3; ++i)
	{
		int findIdx = ip.find('.', idx);
		if (findIdx == std::string::npos)
		{
			return false;
		}

		addr[i] = std::stoi(ip.substr(ip.length() - findIdx));
		++findIdx;
		ip = ip.substr(findIdx);

		if (0 > addr[i] || 255 < addr[i])
		{
			return false;
		}
	}

	// 포트 확인
	int portIdx = ip.find(':', idx);
	if (std::string::npos == portIdx)
	{
		std::cout << "포트를 입력해주세요" << std::endl;
		std::cin >> port;
		_ip += ":";
		_ip += std::to_string(port);
	}
	else
	{
		++portIdx;
		port = stoi(ip.substr(portIdx));
	}

	return true;
}

int main()
{
	// 123.123.511.555:2333
	// 
	std::string ip;
	int port = -1;
	//ip = "123.123.213.123:3000";
	while (true)
	{
		std::cout << "IP를 입력해주세요" << std::endl;
		std::cin >> ip;
		if (false == CheckIP(ip, port))
		{
			std::cout << "IP 인식 실패" << std::endl;
		}
		else
		{
			std::cout << "Ip:" << ip << std::endl;
			std::cout << "Port: " << port << std::endl;
			break;
		}
	}
	
}

