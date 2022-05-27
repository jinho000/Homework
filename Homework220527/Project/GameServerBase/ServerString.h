#pragma once

// �뵵 :
// �з� :
// ÷�� :
class ServerString
{
private: // member var

private:
	ServerString();
	~ServerString();

public: // default

	ServerString(const ServerString& _other) = delete;
	ServerString(ServerString&& _other) = delete;

protected:
	ServerString& operator=(const ServerString& _other) = delete;
	ServerString& operator=(const ServerString&& _other) = delete;

private:

public: // member Func

	// ������� ANSI ���ڵ��� ���
	// Ŭ���̾�Ʈ�κ��� ���޹��� UTF8�����͸� ANSI ���ڿ��� ��ȯ
	static bool UTF8ToANSI(const std::string& _UTF8Str, std::string& _ANSIStrBuffer);
	static bool UTF8ToUNICODE(const std::string& _UTF8Str, std::wstring& _UNICODEStrBuffer);
	static bool UNICODEToANSI(const std::wstring& _UNICODEStr, std::string& _ANSIStrBuffer);

	// ������ ���۽� ANSI���ڿ��� UTF8���ڵ����� ��ȯ
	static bool ANSIToUTF8(const std::string& _ANSIStr, std::string& _UTF8StrBuffer);
	static bool ANSIToUNICODE(const std::string& _ANSIStr, std::wstring& _UNICODEStrBuffer);
	static bool UNICODEToUTF8(const std::wstring& _UNICODEStr, std::string& _UTF8StrBuffer);

	static std::vector<std::string> split(const std::string& input, char delimiter);

	static void Replace(std::string& _Text, const std::string& _Prev, const std::string& _Next, int _Count = 1);

	static void Insert(std::string& _Text, int _Index, const std::string& _InsertText);

	static void TrimRemove(std::string& _Text);

	static void ToUpper(std::string& _Text);

	static void Remove(std::string& _Text, const std::string& _DeleteText);

	static void ClearText(std::string& _Text);
};

