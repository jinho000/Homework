#pragma once

// ���Ǿ��� �����鳢���� ��Ŷ�� ó��(��ε�ĳ����)
// 
class ServerSection
{
private: // member var
	UINT m_sectionIndex;
	UINT m_threadOrder;

public: // default
	ServerSection();
	virtual ~ServerSection();

	ServerSection(const ServerSection& _other) = delete;
	ServerSection(ServerSection&& _other) = delete;
	ServerSection& operator=(const ServerSection& _other) = delete;
	ServerSection& operator=(const ServerSection&& _other) = delete;

public:
	void SetSectionIndex(UINT _sectionIndex) { m_sectionIndex = _sectionIndex; }
	//UINT GetSectionIndex() { return m_sectionIndex; }

	void SetThreadOrder(UINT _threadOrder) { m_threadOrder = _threadOrder; }
	
public: // member Func
	virtual void Init() {};
	//void AccTimeUpdate(float _AccTime);

	virtual void Update(float _time) = 0;

	virtual void Release() {};

};

