#pragma once
#include "UserTable.h"
#include <GameServerBase/ServerBaseObject.h>
#include "ContentStruct.h"

// SessionUserData

// ������ ����ִ� ������ DB������
// ������ ĳ���� ������ �ޱ����� ���ǿ� ���� ����
// ���ǿ� ���� ������ �̸� �޾Ƴ��´�
// (���������� �ʿ��Ҷ� ��� ���ٿ��ʿ䰡 ����)
// (������ ������ ����� ������ ��� ����ȭ��������Ѵ�)
class SessionUserDBData : public ServerBaseObject
{
public: // member var
	std::shared_ptr<UserRow> UserInfo;
	std::vector<FCharacterInfo> UserCharacterList;

public: // default
	SessionUserDBData();
	~SessionUserDBData();

	SessionUserDBData(const SessionUserDBData& _other) = delete;
	SessionUserDBData(SessionUserDBData&& _other) = delete;
	SessionUserDBData& operator=(const SessionUserDBData& _other) = delete;
	SessionUserDBData& operator=(const SessionUserDBData&& _other) = delete;

public: // member Func

	// ������ ĳ������ �ε�����ȯ
	// ���н� -1 ��ȯ
	size_t CheckNickName(const std::string& _nickName);

	// �����̰������ִ� ĳ���͸���Ʈ���� ����
	void DeleteCharacter(const std::string& _nickName);

	const FCharacterInfo& GetCharacter(const std::string& _nickName);
};

