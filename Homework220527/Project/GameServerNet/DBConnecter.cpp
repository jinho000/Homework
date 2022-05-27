#include "pch.h"
#include "DBConnecter.h"
#include <mysql\mysql.h>

#include <GameServerBase/ServerDebug.h>

DBConnecter::DBConnecter()
	: m_mysqlPtr(nullptr)
{
}

DBConnecter::~DBConnecter()
{
	mysql_close(m_mysqlPtr);
	mysql_thread_end();
}

bool DBConnecter::Connect(const std::string _Host, const std::string _Id, const std::string _Pw, const std::string _Schema, unsigned int _Port)
{
	// �̹� ������ ���
	if (nullptr != m_mysqlPtr)
	{
		return false;
	}

	// ����Ʈ init
	m_mysqlPtr = mysql_init(nullptr);
	
	if (nullptr == m_mysqlPtr)
	{
		ServerDebug::AssertDebugMsg("Mysql Init Error");
		return false;
	}

	mysql_options(m_mysqlPtr, MYSQL_SET_CHARSET_NAME, "utf8");

	// ���ÿ� �������� SELECT������ �޾ƺ��� �ְ� ó�����ݴϴ�.
	MYSQL* Handle = mysql_real_connect(m_mysqlPtr, _Host.c_str(), _Id.c_str(), _Pw.c_str(), _Schema.c_str(), 3306, nullptr, CLIENT_MULTI_RESULTS);

	if (m_mysqlPtr != Handle)
	{
		// ���������� �� �����ߴ��� �˷��ݴϴ�.
		const char* Error = mysql_error(m_mysqlPtr);
		ServerDebug::AssertDebugMsg(std::string("Mysql connect Error =>") + Error);
		return false;
	}

	// ���� DB���� ������ ��������
	// �ڵ��ɼ����� �ڵ� ���ο��� �˾Ƽ� ������ �����Ѵ�.
	bool reconnect = true;
	// �ð� 1������ DB�� 
	mysql_options(m_mysqlPtr, MYSQL_OPT_RECONNECT, &reconnect);

	// ���� �����ص� ����?

	 //�� ������� ���������� �˾Ƽ� ���� �յڿ� mysql ������ ������ ���������� ���� 
	 //�����ٰŴϱ�.
	 //�Լ��� ������ ã���� �˴ϴ�.
	 //mysql_query(Handle, "SELECT * FROM userver2.character");

	//mysql_library_end();
	//mysql_close(m_mysqlPtr);

	return true;
}

// ������Ʈ��Ʈ ����
// ������Ʈ��Ʈ�� ���� �������� ���ڰ��� mysql���̺귯�� 
// ���ؿ��� ����ϰ� ������ ����ϴ�
// ���� �����̴�.
std::unique_ptr<DBStatement> DBConnecter::CreateStmt(std::string_view _Query)
{
	// �����׸�Ʈ ������ ������ ���Ѱ����� ���̳��� ������� �̰� �����ʿ䰡 ����.
	MYSQL_STMT* stmt = mysql_stmt_init(m_mysqlPtr);

	if (nullptr == stmt)
	{
		ServerDebug::AssertDebugMsg("mysql Statememnt Create Error");
		return nullptr;
	}

	int result = mysql_stmt_prepare(stmt, _Query.data(), static_cast<unsigned long>(_Query.length()));
	if (0 != result)
	{
		mysql_stmt_close(stmt);
		std::string err = mysql_error(m_mysqlPtr);
		ServerDebug::AssertDebugMsg("mysql Statememnt mysql_stmt_prepare Error");
		return nullptr;
	}

	return std::make_unique<DBStatement>(this, stmt, _Query);
}

std::string DBConnecter::GetLastError()
{
	return mysql_error(m_mysqlPtr);
}

