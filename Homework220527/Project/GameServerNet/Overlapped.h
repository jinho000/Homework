#pragma once

// �뵵 : �񵿱� ��� overlapped ������ ó�� Ŭ����
// �з� :
// ÷�� :
class Overlapped
{
protected: // member var
	WSAOVERLAPPED m_overlapped;

public: // default
	Overlapped();
	virtual ~Overlapped() = 0 {};

	Overlapped(const Overlapped& _other) = delete;
	Overlapped(Overlapped&& _other) = delete;
	Overlapped& operator=(const Overlapped& _other) = delete;
	Overlapped& operator=(const Overlapped&& _other) = delete;

private:

public: // member Func
	virtual void Excute(BOOL _result, DWORD _byteSize) {};
	
	LPWSAOVERLAPPED GetLPOverlapped();
	void ResetOverlapped();
};

