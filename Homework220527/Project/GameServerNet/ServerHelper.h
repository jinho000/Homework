#pragma once

// �뵵 :
// �з� :
// ÷�� :
class ServerHelper
{
public: // member var
	static bool InitSocketLib();
	static std::string GetMyIP();

private: // default
	ServerHelper() = delete;
	~ServerHelper() = delete;

	ServerHelper(const ServerHelper& _other) = delete;
	ServerHelper(ServerHelper&& _other) = delete;

protected:
	ServerHelper& operator=(const ServerHelper& _other) = delete;
	ServerHelper& operator=(const ServerHelper&& _other) = delete;

private:

public: // member Func
};

