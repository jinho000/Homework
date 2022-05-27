#include "pch.h"
#include "DBStatement.h"

#include <GameServerBase/ServerDebug.h>

#include "DBConnecter.h"

DBStatement::DBStatement(DBConnecter* _DBConnecterPtr, MYSQL_STMT* _stmt, std::string_view _Query)
	: m_DBConnecterPtr(_DBConnecterPtr)
	, m_query(_Query)
	, m_stmtPtr(_stmt)
{
	m_paramLengthBuffer.reserve(20);
	m_paramIsNullBuffer.reserve(20);
	m_paramBindBuffer.reserve(1024);
}

void DBStatement::ParamBindString(std::string_view _Value)
{
	m_paramLengthBuffer.emplace_back();
	m_paramIsNullBuffer.emplace_back();
	size_t Size = m_paramBindBuffer.size();
	m_paramBindBuffer.resize(m_paramBindBuffer.size() + _Value.size());

	// ��Ȯ�� �ĺ���
	MYSQL_BIND& Bind = m_parambinds.emplace_back();
	Bind.buffer_type = MYSQL_TYPE_VARCHAR;
	Bind.buffer = &m_paramBindBuffer[Size];
	memset(Bind.buffer, 0x00, _Value.size() + 1);
	memcpy_s(Bind.buffer, _Value.length(), _Value.data(), _Value.length());
	Bind.buffer_length = static_cast<unsigned long>(_Value.length());
	Bind.is_null = reinterpret_cast<bool*>(&m_paramIsNullBuffer[m_paramIsNullBuffer.size() - 1]);
	*Bind.is_null = false;
	Bind.length = &m_paramLengthBuffer[m_paramLengthBuffer.size() - 1];
	*Bind.length = Bind.buffer_length;
}

void DBStatement::ParamBindInt(const int _Value)
{
	m_paramLengthBuffer.emplace_back();
	m_paramIsNullBuffer.emplace_back();
	size_t Size = m_paramBindBuffer.size();
	m_paramBindBuffer.resize(m_paramBindBuffer.size() + sizeof(int));

	// ��Ȯ�� �ĺ���
	MYSQL_BIND& Bind = m_parambinds.emplace_back();
	Bind.buffer_type = MYSQL_TYPE_LONG;
	Bind.buffer = &m_paramBindBuffer[Size];
	memset(Bind.buffer, 0x00, sizeof(int));
	memcpy_s(Bind.buffer, sizeof(int), &_Value, sizeof(int));
	Bind.buffer_length = static_cast<unsigned long>(sizeof(int));
	Bind.is_null = reinterpret_cast<bool*>(&m_paramIsNullBuffer[m_paramIsNullBuffer.size() - 1]);
	*Bind.is_null = false;
	Bind.length = &m_paramLengthBuffer[m_paramLengthBuffer.size() - 1];
	*Bind.length = Bind.buffer_length;
}

void DBStatement::ParamBindFloat(const float _Value)
{
}

std::unique_ptr<DBStatementResult> DBStatement::Execute()
{
	// ?�� 1���ε�
	int ParamCount = mysql_stmt_param_count(m_stmtPtr);

	// ���ε�� ���� �ȵǾ��ְ�
	// �־���� �ʾ����� �ȵȴ�.
	if (ParamCount != m_parambinds.size())
	{
		ServerDebug::AssertDebugMsg("query bind count not Equal");
		return nullptr;
	}

	if (0 != ParamCount)
	{
		if (0 != mysql_stmt_bind_param(m_stmtPtr, &m_parambinds[0]))
		{
			ServerDebug::AssertDebugMsg("mysql_stmt_bind_param Error" + m_DBConnecterPtr->GetLastError());
			return nullptr;
		}
	}

	MYSQL_RES* ResultMetaData = mysql_stmt_result_metadata(m_stmtPtr);
	// �翬�� �� ������ select ������ �ƴ϶��
	// ������� �������� ����?

	std::unique_ptr<DBStatementResult> Result = nullptr;

	if (nullptr != ResultMetaData)
	{
		Result = std::make_unique<DBStatementResult>(m_DBConnecterPtr, m_stmtPtr, m_query);

		// �̰� nullptr�� �ƴ϶�� ������� ���ðŶ�� �̾߱��̰� �ǰ�
		// ������� columncount�� �� rowī��Ʈ�� �˾Ƴ��� �Ѵ�.
		int ColumnCount = mysql_num_fields(ResultMetaData);
		for (size_t i = 0; i < ColumnCount; i++)
		{
			MYSQL_BIND& ResultBind = Result->m_resultBinds.emplace_back();
			Result->m_resultIsNullBuffer.emplace_back();
			Result->m_resultLengthBuffer.emplace_back();

			MYSQL_FIELD& field = ResultMetaData->fields[i];

			size_t BufferStart = Result->m_resultBindBuffer.size();
			// ���� int����
			// ���� string�̿���
			switch (field.type)
			{
			case enum_field_types::MYSQL_TYPE_VAR_STRING:
			{
				Result->m_resultBindBuffer.resize(Result->m_resultBindBuffer.size() + field.length + 1);
				ResultBind.buffer_type = enum_field_types::MYSQL_TYPE_VAR_STRING;
				ResultBind.buffer = &Result->m_resultBindBuffer[BufferStart];
				// ResultBind.buffer = new char[field.length + 1];
				ResultBind.buffer_length = field.length + 1;
				memset(ResultBind.buffer, 0x00, field.length + 1);
				ResultBind.is_null = reinterpret_cast<bool*>(&Result->m_resultIsNullBuffer[Result->m_resultIsNullBuffer.size() - 1]);
				*ResultBind.is_null = false;
				ResultBind.length = &Result->m_resultLengthBuffer[Result->m_resultLengthBuffer.size() - 1];
				break;
			}
			case enum_field_types::MYSQL_TYPE_LONG:
			{
				Result->m_resultBindBuffer.resize(Result->m_resultBindBuffer.size() + sizeof(int));
				ResultBind.buffer_type = enum_field_types::MYSQL_TYPE_LONG;
				ResultBind.buffer = &Result->m_resultBindBuffer[BufferStart];
				// ResultBind.buffer = new char[sizeof(int)];
				ResultBind.buffer_length = sizeof(int);
				memset(ResultBind.buffer, 0x00, sizeof(int));
				ResultBind.is_null = reinterpret_cast<bool*>(&Result->m_resultIsNullBuffer[Result->m_resultIsNullBuffer.size() - 1]);
				*ResultBind.is_null = false;
				ResultBind.length = &Result->m_resultLengthBuffer[Result->m_resultLengthBuffer.size() - 1];
				break;
			}
			case enum_field_types::MYSQL_TYPE_FLOAT:
			{
				Result->m_resultBindBuffer.resize(Result->m_resultBindBuffer.size() + sizeof(float));
				ResultBind.buffer_type = enum_field_types::MYSQL_TYPE_FLOAT;
				ResultBind.buffer = &Result->m_resultBindBuffer[BufferStart];
				// ResultBind.buffer = new char[sizeof(int)];
				ResultBind.buffer_length = sizeof(float);
				memset(ResultBind.buffer, 0x00, sizeof(float));
				ResultBind.is_null = reinterpret_cast<bool*>(&Result->m_resultIsNullBuffer[Result->m_resultIsNullBuffer.size() - 1]);
				*ResultBind.is_null = false;
				ResultBind.length = &Result->m_resultLengthBuffer[Result->m_resultLengthBuffer.size() - 1];
				break;
			}
			default:
				ServerDebug::AssertDebugMsg("mysql result type switch error");
				break;
			}
		}

		if (0 != mysql_stmt_bind_result(m_stmtPtr, &Result->m_resultBinds[0]))
		{
			ServerDebug::AssertDebugMsg("mysql_stmt_bind_result Error" + m_DBConnecterPtr->GetLastError());
			return nullptr;
		}

	}

	// ������ ������.
	if (0 != mysql_stmt_execute(m_stmtPtr))
	{
		m_DBConnecterPtr->GetLastError();
		return nullptr;
	}

	// ���� ����� �޾ƿ°̴ϴ�.
	if (0 != mysql_stmt_store_result(m_stmtPtr))
	{
		ServerDebug::AssertDebugMsg("mysql_stmt_store_result Error" + m_DBConnecterPtr->GetLastError());
		return nullptr;
	}


	// db �� ��� ��ȭ�ư�..
	//uint64_t Id = mysql_stmt_insert_id(m_stmtPtr);
	//// �þ �ο� ������ �˾ƿü��� �ֽ��ϴ�.
	//// ���� ���� �ϳ� ������ ���� �ƴҼ��� �ֽ��ϴ�.
	//uint64_t Row = mysql_stmt_affected_rows(m_stmtPtr);

	// ���ʿ� ����ִ� ���� 
	// ���� �޾ƺ� ���� long

	if (nullptr != ResultMetaData)
	{
		mysql_free_result(ResultMetaData);
	}

	return Result;
	// mysql_stmt_result_metadata(m_stmtPtr);
}
