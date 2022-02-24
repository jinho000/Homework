#include <iostream>
#include <algorithm>

//                 "오늘은 정말 힘들었다"                  "오늘은"          "어제는"
static void Replace(std::string& _Text, const std::string& _Prev, const std::string& _Next, int _Count = 1)
{
	if (_Count <= 0)
	{
		return;
	}

	for (size_t i = 0; i < _Count; i++)
	{
		size_t pos = _Text.find(_Prev);
		if (std::string::npos == pos)
		{
			break;
		}

		_Text.replace(pos, _Prev.size(), _Next);
	}
}

// "ffasdfsdafdas" "cccc"
static void Insert(std::string& _Text, int _Index, const std::string& _InsertText)
{
	if (_Index < 0)
	{
		return;
	}

	if (_Text.size() <= _Index)
	{
		return;
	}

	_Text.insert(_Index, _InsertText);
}

// ReMove
static void Remove(std::string& _Text, const std::string& _DeleteText)
{
	while (true)
	{
		size_t pos = _Text.find(_DeleteText);
		if (std::string::npos == pos)
		{
			break;
		}

		_Text.erase(pos, _DeleteText.size());
	}
}

// ' '
static void TrimRemove(std::string& _Text)
{
	Remove(_Text, " ");
}

// 한글이 섞여있어도.
static void ToUpper(std::string& _Text)
{
	std::transform(_Text.begin(), _Text.end(), _Text.begin(), ::toupper);
}

void TestReplace()
{
	std::string text = "aaaaabbb";
	Replace(text, "aaa", "bbb");

	int a = 0;
}

void TestInsert()
{
	std::string text = "fffff";
	Insert(text, 3, "ddd");
	Insert(text, 4, "ddd");

	int a = 0;
}

void TestRemove()
{
	std::string Text = "asdf defd efdfs esef";

	Remove(Text, " ");
	Remove(Text, "de");
	Remove(Text, "asdf");
}

int main()
{
	TestReplace();
	return 0;
}
