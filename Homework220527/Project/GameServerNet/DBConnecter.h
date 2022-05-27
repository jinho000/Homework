#pragma once
#include "DBStatement.h"

// �뵵 : DB�� �����ϱ� ���� Ŭ����
// �з� :
// ÷�� 
// �ѹ� �����ϸ� �������� ����
//
struct MYSQL;
class DBConnecter
{
private: // member var
	MYSQL* m_mysqlPtr;

public: // default
	DBConnecter();
	~DBConnecter();

	DBConnecter(const DBConnecter& _other) = delete;
	DBConnecter(DBConnecter&& _other) = delete;
	DBConnecter& operator=(const DBConnecter& _other) = delete;
	DBConnecter& operator=(const DBConnecter&& _other) = delete;

private:

public: // member Func
	bool Connect(
		const std::string _Host,
		const std::string _Id,
		const std::string _Pw,
		const std::string _Schema,
		unsigned int _Port
	);

	std::unique_ptr<DBStatement> CreateStmt(std::string_view _Query);
	std::string GetLastError();

};

