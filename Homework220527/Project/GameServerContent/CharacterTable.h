#pragma once
#include <GameServerNet/DBQuery.h>

class CharacterRow : public std::enable_shared_from_this<CharacterRow>
{
public:
	int Index;
	std::string NickName;
	int UserIndex;
	float Att;
	float Hp;
	int LastRoomID;
	float RoomX;
	float RoomY;
	float RoomZ;

public:
	CharacterRow(
		int _Index,
		std::string _NickName,
		int _UserIndex,
		float _Att,
		float _Hp,
		int _LastRoomID,
		float _RoomX,
		float _RoomY,
		float _RoomZ
	) : Index(_Index),
		NickName(_NickName),
		UserIndex(_UserIndex),
		Att(_Att),
		Hp(_Hp),
		LastRoomID(_LastRoomID),
		RoomX(_RoomX),
		RoomY(_RoomY),
		RoomZ(_RoomZ)
	{

	}
};

// �г������� ĳ���� ���� ��������
class CharacterTable_SelectNickName : public DBQuery
{
public:
	std::string						NickName;
	std::shared_ptr<CharacterRow>	RowData;

public:
	CharacterTable_SelectNickName(std::string _nickName);
	bool DoQuery() override;
};

// �����ε����� ��ü ĳ���� ���� ��������
class CharacterTable_SelectUserCharacters : public DBQuery
{
public:
	int											UserIndex;
	std::vector<std::shared_ptr<CharacterRow>>	RowDatas;

public:
	CharacterTable_SelectUserCharacters(int _userIdx);

	bool DoQuery() override;
};


// �г��Ӱ� �����ε����� ĳ�������̺� ���� �ֱ�
class CharacterTable_CreateCharacter : public DBQuery
{
public:
	std::string NickName;
	int			UserId;

public:
	CharacterTable_CreateCharacter(std::string _NickName, int _userId);
	bool DoQuery() override;
};

// �ε����� �ش� ĳ���� �����ϱ�
class CharacterTable_DeleteCharacter : public DBQuery
{
public:
	int	_characterIndex;

public:
	CharacterTable_DeleteCharacter(int _characterIndex);
	bool DoQuery() override;
};
