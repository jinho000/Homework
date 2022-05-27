#pragma once

// �뵵 :
// �з� :
// ÷�� :
class DBConnecter;
class DBQuery
{
protected: // member var
	DBConnecter*	DBConnecterPtr;
	const char*		QueryString;

public: // default
	DBQuery(const char* _Query);
	~DBQuery();

	DBQuery(const DBQuery& _other) = delete;
	DBQuery(DBQuery&& _other) = delete;
	DBQuery& operator=(const DBQuery& _other) = delete;
	DBQuery& operator=(const DBQuery&& _other) = delete;


public: // member Func
	// ���Լ��� �����ؾ߸� ������ db�� ���ư���.
	virtual bool DoQuery() = 0;
};

