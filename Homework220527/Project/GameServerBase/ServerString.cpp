#include "pch.h"
#include "ServerString.h"
#include "ServerDebug.h"

ServerString::ServerString()
{
}

ServerString::~ServerString()
{
}

bool ServerString::UTF8ToANSI(const std::string& _UTF8bytes, std::string& _outBuffer)
{
    std::wstring tempUNICODE;
    if (false == UTF8ToUNICODE(_UTF8bytes, tempUNICODE))
    {
        return false;
    }

    if (false == UNICODEToANSI(tempUNICODE, _outBuffer))
    {
        return false;
    }

    return true;
}

bool ServerString::UTF8ToUNICODE(const std::string& _UTF8bytes, std::wstring& _outBuffer)
{
	// ���� ����
	_outBuffer.clear();

    // ��ȯ�� ���ڵ��� ���� ���� ���� ���ϱ�
    int len = MultiByteToWideChar(
        CP_UTF8, 
        0, 
        _UTF8bytes.c_str(),
        static_cast<int>(_UTF8bytes.size()),
        NULL, 
        0
    );

    if (len <= 0)
    {
        // ��ȯ���� 0���� ���ų� ������ ����
        ServerDebug::GetLastErrorPrint();
        return false;
    }

    // �����ڵ� out buffer�� ä���
    _outBuffer.resize(len + 10);
    len = MultiByteToWideChar(
        CP_UTF8,
        0,
        _UTF8bytes.c_str(),
        static_cast<int>(_UTF8bytes.size()),
        _outBuffer.data(),
        static_cast<int>(_outBuffer.size())
    );

    if (len <= 0)
    {
        // ��ȯ���� 0���� ���ų� ������ ����
        ServerDebug::GetLastErrorPrint();
        return false;
    }
    
	return true;
}

bool ServerString::UNICODEToANSI(const std::wstring& _unicode, std::string& _outBuffer)
{
    // ���� ����
    _outBuffer.clear();

    // ��ȯ�� ���ڵ��� ���� ���� ���� ���ϱ�
    int len = WideCharToMultiByte(
        CP_ACP,
        0,
        _unicode.c_str(),
        static_cast<int>(_unicode.size()),
        NULL,
        0,
        NULL,
        NULL
    );

    if (len <= 0)
    {
        // ��ȯ���� 0���� ���ų� ������ ����
        ServerDebug::GetLastErrorPrint();
        return false;
    }

    // outBuffer�� ���� ä���
    _outBuffer.resize(len + 10);
    len = WideCharToMultiByte(
        CP_ACP,
        0,
        _unicode.c_str(),
        static_cast<int>(_unicode.size()),
        _outBuffer.data(),
        static_cast<int>(_outBuffer.size()),
        NULL,
        NULL
    );

    if (len <= 0)
    {
        // ��ȯ���� 0���� ���ų� ������ ����
        ServerDebug::GetLastErrorPrint();
        return false;
    }

    return true;
}

bool ServerString::ANSIToUTF8(const std::string& _ANSIStr, std::string& _UTF8StrBuffer)
{
    std::wstring tempUNICODE;
    if (false == ANSIToUNICODE(_ANSIStr, tempUNICODE))
    {
        return false;
    }

    if (false == UNICODEToUTF8(tempUNICODE, _UTF8StrBuffer))
    {
        return false;
    }

    return true;
}

bool ServerString::ANSIToUNICODE(const std::string& _ANSIStr, std::wstring& _UNICODEStrBuffer)
{
    _UNICODEStrBuffer.clear();

    int len = MultiByteToWideChar(
        CP_ACP,
        0,
        _ANSIStr.c_str(),
        static_cast<int>(_ANSIStr.size()),
        nullptr,
        0
    );

    if (len <= 0)
    {
        // ��ȯ���� 0���� ���ų� ������ ����
        ServerDebug::GetLastErrorPrint();
        return false;
    }

    _UNICODEStrBuffer.resize(len + 10);
    len = MultiByteToWideChar(
        CP_ACP,
        0,
        _ANSIStr.c_str(),
        static_cast<int>(_ANSIStr.size()),
        _UNICODEStrBuffer.data(),
        static_cast<int>(_UNICODEStrBuffer.size())
    );

    if (len <= 0)
    {
        // ��ȯ���� 0���� ���ų� ������ ����
        ServerDebug::GetLastErrorPrint();
        return false;
    }

    return true;
}

bool ServerString::UNICODEToUTF8(const std::wstring& _UNICODEStr, std::string& _UTF8StrBuffer)
{
    _UTF8StrBuffer.clear();

    int len = WideCharToMultiByte(
        CP_UTF8,
        0,
        _UNICODEStr.c_str(),
        static_cast<int>(_UNICODEStr.size()),
        nullptr,
        0,
        nullptr,
        nullptr
    );
    
    if (len <= 0)
    {
        // ��ȯ���� 0���� ���ų� ������ ����
        ServerDebug::GetLastErrorPrint();
        return false;
    }

    _UTF8StrBuffer.resize(len + 10);
    len = WideCharToMultiByte(
        CP_UTF8,
        0,
        _UNICODEStr.c_str(),
        static_cast<int>(_UNICODEStr.size()),
        _UTF8StrBuffer.data(),
        static_cast<int>(_UTF8StrBuffer.size()),
        nullptr,
        nullptr
    );

    if (len <= 0)
    {
        // ��ȯ���� 0���� ���ų� ������ ����
        ServerDebug::GetLastErrorPrint();
        return false;
    }

    return true;
}

std::vector<std::string> ServerString::split(const std::string& input, char delimiter)
{
    std::vector<std::string> answer;
    std::stringstream ss(input);
    std::string temp;

    while (getline(ss, temp, delimiter))
    {
        if (temp == "")
        {
            continue;
        }
        answer.push_back(temp);
    }

    return answer;
}

void ServerString::Replace(std::string& _Text, const std::string& _Prev, const std::string& _Next, int _Count /*= 1*/)
{
    int cnt = 0;
    while (_Count > cnt++)
    {
        size_t startIdx = _Text.find(_Prev);
        if (startIdx == std::string::npos)
            return;
        _Text.replace(startIdx, _Prev.length(), _Next);
    }
    return;
}

// �����Ϸ��� �ε����� ���ڿ� ���̺��� Ŭ ��� ���� x, �ε����� 0���� ������� ���� x
void ServerString::Insert(std::string& _Text, int _Index, const std::string& _InsertText)
{
    if (_Text.length() < _Index || _Index < 0)
        return;
    _Text.insert(_Index, _InsertText);
}

// ���� ����
void ServerString::TrimRemove(std::string& _Text)
{
    Replace(_Text, " ", "", static_cast<int>(_Text.length()));
}

void ServerString::ToUpper(std::string& _Text)
{
    std::transform(_Text.begin(), _Text.end(), _Text.begin(), [](const char& c) { return std::toupper(c); });
}

// ���� ����
void ServerString::Remove(std::string& _Text, const std::string& _DeleteText)
{
    Replace(_Text, _DeleteText, "", static_cast<int>(_Text.length()));
}

void ServerString::ClearText(std::string& _Text)
{
    Replace(_Text, "\t", "", static_cast<int>(_Text.length()));
    Replace(_Text, "\n", "", static_cast<int>(_Text.length()));
}