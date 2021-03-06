// MessageToUnreal.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <GameServerBase/GameServerDebug.h>
#include <GameServerBase/GameServerFile.h>
#include <GameServerBase/GameServerDirectory.h>
#include <GameServerBase/GameServerString.h>

#pragma comment(lib, "GameServerBase.lib")

class MemberInfo
{
public:
	std::string MemberText;
	std::string Type;
	std::string Name;
};

class MessageInfo
{
public:
	std::string Name;
	std::vector<MemberInfo> Member;
};

struct CopyCode
{
	std::string SavePath;
	std::string Code;
};


void SerializerTypeCheck(std::string& _Text, MemberInfo& _MemberInfo)
{
	if (_MemberInfo.Type == "std::string")
	{
		_Text += "        _Serializer << " + _MemberInfo.Name + ";\n";
	}
	else if (_MemberInfo.Type == "int")
	{
		_Text += "        _Serializer << " + _MemberInfo.Name + ";\n";
	}
	else if (_MemberInfo.Type == "FVector")
	{
		_Text += "        _Serializer << " + _MemberInfo.Name + ";\n";
	}
	else
	{
		if (_MemberInfo.Type[0] == 'E')
		{
			_Text += "        _Serializer.WriteEnum(" + _MemberInfo.Name + ");\n";
		}
		else
		{
			GameServerDebug::AssertDebugMsg("파악할수 없는 타입이 체크되었습니다. Name : " + _MemberInfo.Name + " Type : " + _MemberInfo.Type);
		}
	}
}

void DeSerializerTypeCheck(std::string& _Text, MemberInfo& _MemberInfo)
{
	if (_MemberInfo.Type == "std::string")
	{
		_Text += "        _Serializer >> " + _MemberInfo.Name + ";\n";
	}
	else if (_MemberInfo.Type == "int")
	{
		_Text += "        _Serializer >> " + _MemberInfo.Name + ";\n";
	}
	else if (_MemberInfo.Type == "FVector")
	{
		_Text += "        _Serializer >> " + _MemberInfo.Name + ";\n";
	}
	else
	{
		if (_MemberInfo.Type[0] == 'E')
		{
			_Text += "        _Serializer.ReadEnum(" + _MemberInfo.Name + ");\n";
		}
		else
		{
			GameServerDebug::AssertDebugMsg("파악할수 없는 타입이 체크되었습니다. Name : " + _MemberInfo.Name + " Type : " + _MemberInfo.Type);
		}
	}
}



void MessageHeaderCreate(std::vector<MessageInfo>& _Collection, const std::string Path, std::vector<CopyCode>& _copyList)
{
	std::string MessageText;

	MessageText += "#pragma once\n";
	MessageText += "#include \"GameServerMessage.h\"\n";
	MessageText += "\n";


	for (size_t i = 0; i < _Collection.size(); i++)
	{
		MessageText += "class " + _Collection[i].Name + "Message : public GameServerMessage                    \n";
		MessageText += "{                                                               \n";
		MessageText += "public:                                                         \n";

		std::vector<MemberInfo>& MemberList = _Collection[i].Member;

		for (size_t m = 0; m < MemberList.size(); m++)
		{
			MessageText += "\t" + MemberList[m].MemberText + ";\n";
		}

		MessageText += "                                                                \n";
		MessageText += "public:                                                         \n";
		MessageText += "    " + _Collection[i].Name + "Message()                                               \n";
		MessageText += "        : GameServerMessage(MessageId::" + _Collection[i].Name + ")                    \n";
		for (size_t m = 0; m < MemberList.size(); m++)
		{
			MessageText += "        , " + MemberList[m].Name + "()\n";
		}
		MessageText += "    {                                                           \n";
		MessageText += "                                                                \n";
		MessageText += "    }                                                           \n";
		MessageText += "                                                                \n";
		MessageText += "    virtual ~" + _Collection[i].Name + "Message() {}                                   \n";
		MessageText += "                                                                \n";
		MessageText += "    virtual int SizeCheck()                                     \n";
		MessageText += "    {                                                           \n";
		if (0 != MemberList.size())
		{
			MessageText += "\t\treturn ";

			for (size_t m = 0; m < MemberList.size(); m++)
			{
				MessageText += "DataSizeCheck(" + MemberList[m].Name + ")";
				MessageText += m != MemberList.size() - 1 ? " + " : ";\n";
			}
		}
		else
		{
			MessageText += "\t\treturn 0;";
		}
		MessageText += "    }                                                           \n";
		MessageText += "                                                                \n";
		MessageText += "    void Serialize(GameServerSerializer& _Serializer)           \n";
		MessageText += "    {                                                           \n";
		MessageText += "        GameServerMessage::Serialize(_Serializer);              \n";
		for (size_t m = 0; m < MemberList.size(); m++)
		{
			SerializerTypeCheck(MessageText, MemberList[m]);
		}
		MessageText += "\n";
		MessageText += "    }                                                           \n";
		MessageText += "                                                                \n";
		MessageText += "    void DeSerialize(GameServerSerializer& _Serializer)         \n";
		MessageText += "    {                                                           \n";
		MessageText += "        GameServerMessage::DeSerialize(_Serializer);            \n";
		for (size_t m = 0; m < MemberList.size(); m++)
		{
			DeSerializerTypeCheck(MessageText, MemberList[m]);
		}
		MessageText += "\n";
		MessageText += "    }                                                           \n";
		MessageText += "};                                                              \n";
		MessageText += "\n";
	}

	//GameServerFile SaveFile = GameServerFile{ Path, "wt" };
	//SaveFile.Write(MessageText.c_str(), MessageText.size());

	_copyList.push_back({ Path, MessageText });
}

bool CheckMemberVarType(const std::string& _Text)
{
	if (_Text.empty())
	{
		return false;
	}

	if (_Text != "std::string" &&
		_Text != "int" &&
		_Text != "FVector" &&
		_Text[0] != 'E'
		)
	{
		return false;
	}

	return true;
}


int FindCharCount(const std::string& _text, char _ch)
{
	int count = 0;
	int findPos = 0;
	while (true)
	{
		findPos = _text.find(_ch, findPos + 1);
		if (std::string::npos == findPos)
		{
			break;
		}
		++count;
	}

	return count;
}


bool MessageReflection(std::vector<MessageInfo>& _Collection, const std::string& Code)
{
	std::vector<std::string> ClientMessageString = GameServerString::split(Code, '|');
	for (size_t i = 0; i < ClientMessageString.size(); i++)
	{
		GameServerString::ClearText(ClientMessageString[i]);
		if (ClientMessageString[i] == "")
		{
			continue;
		}

		if (std::string::npos == ClientMessageString[i].find('-'))
		{
			std::cout << "구문에 \'-\'가 없습니다" << std::endl;
			std::cout << "[" + ClientMessageString[i] + "]" << std::endl;
			return false;
		}

		if (2 <= FindCharCount(ClientMessageString[i], '-'))
		{
			std::cout << "\'-\'가 2개 이상입니다" << std::endl;
			std::cout << "[" + ClientMessageString[i] + "]" << std::endl;
			return false;
		}

		std::vector<std::string> MemberAndName = GameServerString::split(ClientMessageString[i], '-');
		std::string& Name = MemberAndName[0];
		if (std::string::npos != Name.find(' ')
			|| std::string::npos != Name.find('\n')
			|| std::string::npos != Name.find('\t'))
		{
			std::cout << "타입이름에 공백이 있습니다" << std::endl;
			std::cout << "[" + Name + "]" << std::endl;

			std::cout << "==============" << std::endl;
			std::cout << ClientMessageString[i] << std::endl;

			return false;
		}

		MessageInfo Info;
		Info.Name = Name;

		// 멤버변수가 없는경우
		if (1 >= MemberAndName.size())
		{
			_Collection.push_back(Info);
			continue;
		}


		std::string& MmeberInfo = MemberAndName[1];
		std::vector<std::string> Members = GameServerString::split(MmeberInfo, ';');

		for (size_t i = 0; i < Members.size(); i++)
		{
			MemberInfo NewInfo;
			NewInfo.MemberText = Members[i];

			std::vector<std::string> TypeAndName = GameServerString::split(NewInfo.MemberText, ' ');
			if (1 == TypeAndName.size())
			{
				std::cout << "타입또는 변수가 하나이거나 사이에 \' \' 문자가 없습니다 " << std::endl;
				std::cout << "[" + NewInfo.MemberText + "]" << std::endl;
				std::cout << "==============" << std::endl;
				std::cout << MmeberInfo << std::endl;
				return false;
			}

			if (2 < TypeAndName.size())
			{
				std::cout << "타입과 변수이름은 하나씩 있어야합니다 " << std::endl;
				std::cout << "[" + NewInfo.MemberText + "]" << std::endl;
				std::cout << "==============" << std::endl;
				std::cout << MmeberInfo << std::endl;
				return false;
			}

			if (false == CheckMemberVarType(TypeAndName[0]))
			{
				std::cout << "파악할수 없는 타입이 체크되었습니다." << std::endl;
				std::cout << "Type [" + TypeAndName[0] + "] Name [" + TypeAndName[1] + "]" << std::endl;
				std::cout << "==============" << std::endl;
				std::cout << MmeberInfo << std::endl;
				return false;
			}

			NewInfo.Type = TypeAndName[0];
			NewInfo.Name = TypeAndName[1];

			Info.Member.push_back(NewInfo);
		}

		_Collection.push_back(Info);
	}

	return true;
}

int main()
{
	COORD pos = { 0, 0 };

	HANDLE stdHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(stdHandle, pos);

	std::vector<MessageInfo> AllMessage;
	std::vector<MessageInfo> ClientMessage;
	std::vector<MessageInfo> ServerMessage;
	std::vector<MessageInfo> ServerClientMessage;
	std::vector<CopyCode> CopyList;

	// 만들고 나면 다 단순복사가 됩니다 ok?
	{
		GameServerDirectory LoadDir;
		LoadDir.MoveParent("PorjectCode");
		if (false == LoadDir.MoveChild("GameServerMessage\\Info"))
		{
			std::cout << "파일 경로 오류" << std::endl;
			return 1;
		}

		{
			GameServerFile LoadFile = { LoadDir.PathToPlusFileName("MessageClientToServer.txt"), "rt" };
			std::string Code = LoadFile.GetString();
			if (false == MessageReflection(ClientMessage, Code))
			{
				return 1;
			}
			int a = 0;
		}

		{
			GameServerFile LoadFile = { LoadDir.PathToPlusFileName("MessageServerToClient.txt"), "rt" };
			std::string Code = LoadFile.GetString();

			if (false == MessageReflection(ServerMessage, Code))
			{
				return 1;
			}
			int a = 0;
		}

		{
			GameServerFile LoadFile = { LoadDir.PathToPlusFileName("MessageServerAndClient.txt"), "rt" };
			std::string Code = LoadFile.GetString();

			if (false == MessageReflection(ServerClientMessage, Code))
			{
				return 1;
			}
			int a = 0;
		}

		for (size_t i = 0; i < ClientMessage.size(); i++)
		{
			AllMessage.push_back(ClientMessage[i]);
		}
		for (size_t i = 0; i < ServerMessage.size(); i++)
		{
			AllMessage.emplace_back(ServerMessage[i]);
		}
		for (size_t i = 0; i < ServerClientMessage.size(); i++)
		{
			AllMessage.emplace_back(ServerClientMessage[i]);
		}


	}


	/////////////////////////////////// 서버 파일생성
	{

		{
			///ENUMFILE CREATE////////////////////////////////////////////////////////////////////////////
			GameServerDirectory FileDir;
			FileDir.MoveParent("PorjectCode");
			if (false == FileDir.MoveChild("GameServerMessage"))
			{
				return 1;
			}

			std::string EnumFileText = "#pragma once\n\nenum class MessageId \n{\n";

			for (size_t i = 0; i < AllMessage.size(); i++)
			{
				EnumFileText += "\t" + AllMessage[i].Name + ",\n";
			}

			EnumFileText += "\t";
			EnumFileText += "MAX";
			EnumFileText += "\n";
			EnumFileText += "};";

			std::string SavePath = FileDir.PathToPlusFileName("MessageIdEnum.h");
			//GameServerFile SaveFile = GameServerFile{ SavePath, "wt" };
			//SaveFile.Write(EnumFileText.c_str(), EnumFileText.size());
			CopyList.push_back({ SavePath, EnumFileText });
			///////////////////////////////////////////////////////////////////////////////
		}

		{
			///CONVERT FILE CREATE////////////////////////////////////////////////////////////////////////////
			GameServerDirectory FileDir;
			FileDir.MoveParent("PorjectCode");
			if (false == FileDir.MoveChild("GameServerMessage"))
			{
				return 1;
			}

			std::string ConvertFileText = "#include \"PreCompile.h\"\n";
			ConvertFileText += "#include \"MessageConverter.h\"\n";
			ConvertFileText += "#include <memory>\n";
			ConvertFileText += "MessageConverter::MessageConverter(const std::vector<unsigned char>&_buffer)\n";
			ConvertFileText += "\t: buffer_(_buffer)\n";
			ConvertFileText += "{\n";
			ConvertFileText += "\tGameServerSerializer Sr = GameServerSerializer(buffer_);\n";
			ConvertFileText += "\n";
			ConvertFileText += "\tMessageId Type;\n";
			ConvertFileText += "\tmemcpy_s(&Type, sizeof(MessageId), &buffer_[0], sizeof(MessageId));\n";
			ConvertFileText += "\tswitch (Type)\n\t{\n";

			for (size_t i = 0; i < AllMessage.size(); i++)
			{
				ConvertFileText += "\tcase MessageId::" + AllMessage[i].Name + ":\n";
				ConvertFileText += "\t\tMessage_ = std::make_shared<" + AllMessage[i].Name + "Message>();\n";
				ConvertFileText += "\t\tbreak;\n";
			}

			ConvertFileText += "\tdefault:\n\t\treturn;\n\t}\n\tMessage_->DeSerialize(Sr);\n}";

			std::string SavePath = FileDir.PathToPlusFileName("MessageConverter.cpp");
			//GameServerFile SaveFile = GameServerFile{ SavePath, "wt" };
			//SaveFile.Write(ConvertFileText.c_str(), ConvertFileText.size());

			CopyList.push_back({ SavePath, ConvertFileText });
			///////////////////////////////////////////////////////////////////////////////
		}

		///Message Header////////////////////////////////////////////////////////////////////////////
		{
			GameServerDirectory FileDir;
			FileDir.MoveParent("PorjectCode");
			if (false == FileDir.MoveChild("GameServerMessage"))
			{
				return 1;
			}

			MessageHeaderCreate(ClientMessage, FileDir.PathToPlusFileName("ClientToServer.h"), CopyList);
			MessageHeaderCreate(ServerMessage, FileDir.PathToPlusFileName("ServerToClient.h"), CopyList);
			MessageHeaderCreate(ServerClientMessage, FileDir.PathToPlusFileName("ServerAndClient.h"), CopyList);
		}
		///////////////////////////////////////////////////////////////////////////////
		{
			///DisFile CREATE////////////////////////////////////////////////////////////////////////////
			GameServerDirectory FileDir;
			FileDir.MoveParent("PorjectCode");
			if (false == FileDir.MoveChild("GameServerApp"))
			{
				return 1;
			}

			std::string DisText;

			DisText += "#include \"PreCompile.h\"																																							\n";
			DisText += "#include \"ServerDispatcher.h\"																																						\n";
			DisText += "#include <GameServerBase\\GameServerDebug.h>																																			\n";
			DisText += "																																													\n";
			for (size_t i = 0; i < ClientMessage.size(); i++)
			{
				DisText += "#include \"ThreadHandler" + ClientMessage[i].Name + "Message.h\"\n";
			}

			for (size_t i = 0; i < ServerClientMessage.size(); i++)
			{
				DisText += "#include \"ThreadHandler" + ServerClientMessage[i].Name + "Message.h\"\n";
			}
			DisText += "																																													\n";
			DisText += "Dispatcher<TCPSession> Dis;																																							\n";
			DisText += "																																													\n";
			DisText += "template<typename MessageHandler, typename MessageType>																																\n";
			DisText += "void OnMessageProcess(std::shared_ptr<TCPSession> _Session, std::shared_ptr<GameServerMessage> _Message)																			\n";
			DisText += "{																																													\n";
			DisText += "	std::shared_ptr<MessageType> ConvertMessage = std::dynamic_pointer_cast<MessageType>(_Message);																					\n";
			DisText += "	if (nullptr == ConvertMessage)																																					\n";
			DisText += "	{																																												\n";
			DisText += "		GameServerDebug::LogError(\"ConvertError\");																																\n";
			DisText += "		return;																																										\n";
			DisText += "	}																																												\n";
			DisText += "																																													\n";
			DisText += "	std::shared_ptr<MessageHandler> Cmd = std::make_shared<MessageHandler>(_Session, ConvertMessage);																				\n";
			DisText += "	Cmd->Start();																																									\n";
			DisText += "}																																													\n";
			DisText += "																																													\n";
			DisText += "void DispatcherRegistration()																																						\n";
			DisText += "{																																													\n";
			for (size_t i = 0; i < ClientMessage.size(); i++)
			{
				DisText += "	Dis.AddHandler(static_cast<uint32_t>(MessageId::" + ClientMessage[i].Name + "), std::bind(&OnMessageProcess<ThreadHandler" + ClientMessage[i].Name + "Message, " + ClientMessage[i].Name + "Message>, std::placeholders::_1, std::placeholders::_2));	\n";
			}

			for (size_t i = 0; i < ServerClientMessage.size(); i++)
			{
				DisText += "	Dis.AddHandler(static_cast<uint32_t>(MessageId::" + ServerClientMessage[i].Name + "), std::bind(&OnMessageProcess<ThreadHandler" + ServerClientMessage[i].Name + "Message, " + ServerClientMessage[i].Name + "Message>, std::placeholders::_1, std::placeholders::_2));	\n";
			}
			DisText += "}																																													\n";

			std::string SavePath = FileDir.PathToPlusFileName("ServerDispatcher.cpp");
			GameServerFile SaveFile = GameServerFile{ SavePath, "wt" };
			SaveFile.Write(DisText.c_str(), DisText.size());

			CopyList.push_back({ SavePath , DisText });
		}

	}


	/////////////////////////////////////////////////////////////// 언리얼로 수정 파일 이동.
	{
		GameServerDirectory FileDir;
		FileDir.MoveParent();
		if (false == FileDir.MoveChild("GameServerBase"))
		{
			return 1;
		}

		GameServerDirectory SaveDir;
		SaveDir.MoveParent();
		SaveDir.MoveParent();
		if (false == SaveDir.MoveChild("UnrealClient\\Source\\UnrealClient\\Message"))
		{
			return 1;
		}


		{
			GameServerFile LoadFile = { FileDir.PathToPlusFileName("GameServerSerializer.h"), "rt" };
			std::string Code = LoadFile.GetString();

			Code.replace(Code.find("#include \"GameServerMathStruct.h\"\n")
				, strlen("#include \"GameServerMathStruct.h\"\n"), "\n");

			std::string SavePath = SaveDir.PathToPlusFileName("GameServerSerializer.h");
			//GameServerFile SaveFile = GameServerFile{ SavePath, "wt" };
			//SaveFile.Write(Code.c_str(), Code.size());

			CopyList.push_back({ SavePath , Code });
		}

		{
			GameServerFile LoadFile = { FileDir.PathToPlusFileName("GameServerSerializer.cpp"), "rt" };
			std::string Code = LoadFile.GetString();

			Code.erase(0, strlen("#include \"PreCompile.h\"") + 1);
			std::string SavePath = SaveDir.PathToPlusFileName("GameServerSerializer.cpp");

			//GameServerFile SaveFile = GameServerFile{ SavePath, "wt" };
			//SaveFile.Write(Code.c_str(), Code.size());

			CopyList.push_back({ SavePath , Code });
		}
	}


	{
		GameServerDirectory FileDir;
		FileDir.MoveParent();
		if (false == FileDir.MoveChild("GameServerMessage"))
		{
			return 1;
		}

		GameServerDirectory SaveDir;
		SaveDir.MoveParent();
		SaveDir.MoveParent();
		if (false == SaveDir.MoveChild("UnrealClient\\Source\\UnrealClient\\Message"))
		{
			return 1;
		}

		{
			GameServerFile LoadFile = { FileDir.PathToPlusFileName("GameServerMessage.h"), "rt" };
			std::string Code = LoadFile.GetString();

			Code.replace(Code.find("#include <GameServerBase/GameServerMathStruct.h>\n")
				, strlen("#include <GameServerBase/GameServerMathStruct.h>\n"), "\n");

			Code.replace(Code.find("#include <GameServerBase/GameServerSerializer.h>\n")
				, strlen("#include <GameServerBase/GameServerSerializer.h>\n"), "#include \"GameServerSerializer.h\"\n");

			std::string SavePath = SaveDir.PathToPlusFileName("GameServerMessage.h");
			//GameServerFile SaveFile = GameServerFile{ SavePath, "wt" };
			//SaveFile.Write(Code.c_str(), Code.size());

			CopyList.push_back({ SavePath , Code });
		}


		{
			GameServerFile LoadFile = { FileDir.PathToPlusFileName("ServerToClient.h"), "rt" };
			std::string Code = LoadFile.GetString();
			std::string SavePath = SaveDir.PathToPlusFileName("ServerToClient.h");
			//GameServerFile SaveFile = GameServerFile{ SavePath, "wt" };
			//SaveFile.Write(Code.c_str(), Code.size());

			CopyList.push_back({ SavePath , Code });
		}


		{
			GameServerFile LoadFile = { FileDir.PathToPlusFileName("ClientToServer.h"), "rt" };
			std::string Code = LoadFile.GetString();
			std::string SavePath = SaveDir.PathToPlusFileName("ClientToServer.h");
			//GameServerFile SaveFile = GameServerFile{ SavePath, "wt" };
			//SaveFile.Write(Code.c_str(), Code.size());

			CopyList.push_back({ SavePath , Code });
		}


		{
			GameServerFile LoadFile = { FileDir.PathToPlusFileName("ServerAndClient.h"), "rt" };
			std::string Code = LoadFile.GetString();
			std::string SavePath = SaveDir.PathToPlusFileName("ServerAndClient.h");
			//GameServerFile SaveFile = GameServerFile{ SavePath, "wt" };
			//SaveFile.Write(Code.c_str(), Code.size());

			CopyList.push_back({ SavePath , Code });
		}


		{
			GameServerFile LoadFile = { FileDir.PathToPlusFileName("Messages.h"), "rt" };
			std::string Code = LoadFile.GetString();


			//Code.replace(Code.find("#include <GameServerBase/GameServerSerializer.h>\n")
			//    , strlen("#include <GameServerBase/GameServerSerializer.h>\n"), "#include \"GameServerSerializer.h\"\n");


			std::string SavePath = SaveDir.PathToPlusFileName("Messages.h");
			//GameServerFile SaveFile = GameServerFile{ SavePath, "wt" };
			//SaveFile.Write(Code.c_str(), Code.size());

			CopyList.push_back({ SavePath , Code });
		}



		{
			GameServerFile LoadFile = { FileDir.PathToPlusFileName("MessageIdEnum.h"), "rt" };
			std::string Code = LoadFile.GetString();

			std::string SavePath = SaveDir.PathToPlusFileName("MessageIdEnum.h");
			//GameServerFile SaveFile = GameServerFile{ SavePath, "wt" };
			//SaveFile.Write(Code.c_str(), Code.size());

			CopyList.push_back({ SavePath , Code });
		}

		{
			GameServerFile LoadFile = { FileDir.PathToPlusFileName("ContentsEnums.h"), "rt" };
			std::string Code = LoadFile.GetString();

			std::string SavePath = SaveDir.PathToPlusFileName("ContentsEnums.h");
			//GameServerFile SaveFile = GameServerFile{ SavePath, "wt" };
			//SaveFile.Write(Code.c_str(), Code.size());

			CopyList.push_back({ SavePath , Code });
		}


		{
			GameServerFile LoadFile = { FileDir.PathToPlusFileName("MessageConverter.h"), "rt" };
			std::string Code = LoadFile.GetString();

			std::string SavePath = SaveDir.PathToPlusFileName("MessageConverter.h");
			//GameServerFile SaveFile = GameServerFile{ SavePath, "wt" };
			//SaveFile.Write(Code.c_str(), Code.size());

			CopyList.push_back({ SavePath , Code });
		}

		{
			GameServerFile LoadFile = { FileDir.PathToPlusFileName("MessageConverter.cpp"), "rt" };
			std::string Code = LoadFile.GetString();

			Code.erase(0, strlen("#include \"PreCompile.h\"") + 1);

			std::string SavePath = SaveDir.PathToPlusFileName("MessageConverter.cpp");
			//GameServerFile SaveFile = GameServerFile{ SavePath, "wt" };
			//SaveFile.Write(Code.c_str(), Code.size());

			CopyList.push_back({ SavePath , Code });
		}

		{
			///DisFile CREATE////////////////////////////////////////////////////////////////////////////
			std::string DisText;

			DisText += "#pragma once																									  \n";
			DisText += "#include \"CoreMinimal.h\"																						  \n";
			DisText += "#include <functional>																							 \n";
			DisText += "																												  \n";
			for (size_t i = 0; i < ServerMessage.size(); i++)
			{
				DisText += "#include \"ThreadHandler" + ServerMessage[i].Name + "Message.h\"\n";
			}

			for (size_t i = 0; i < ServerClientMessage.size(); i++)
			{
				DisText += "#include \"ThreadHandler" + ServerClientMessage[i].Name + "Message.h\"\n";
			}
			DisText += "																												  \n";
			DisText += "template<typename MessageHandler, typename MessageType>															  \n";
			DisText += "void OnMessageProcess(std::shared_ptr<GameServerMessage> _Message, UClientGameInstance* _Inst, UWorld* _World)	  \n";
			DisText += "{																												  \n";
			DisText += "	std::shared_ptr<MessageType> ConvertMessage = std::static_pointer_cast<MessageType>(_Message);				  \n";
			DisText += "	if (nullptr == ConvertMessage)																				  \n";
			DisText += "	{																											  \n";
			DisText += "		return;																									  \n";
			DisText += "	}																											  \n";
			DisText += "																												  \n";
			DisText += "	MessageHandler Cmd = MessageHandler(ConvertMessage);														  \n";
			DisText += "	Cmd.Init(_Inst, _World);																					  \n";
			DisText += "	Cmd.Start();																								  \n";
			DisText += "}																												  \n";
			DisText += "																												  \n";
			DisText += "void CheckHandler(Dispatcher& Dis, class UClientGameInstance* Inst, UWorld* World)								  \n";
			DisText += "{														\n";
			for (size_t i = 0; i < ServerMessage.size(); i++)
			{
				DisText += "	Dis.AddHandler(MessageId::" + ServerMessage[i].Name + ", std::bind(&OnMessageProcess<ThreadHandler" + ServerMessage[i].Name + "Message, " + ServerMessage[i].Name + "Message>, std::placeholders::_1, Inst, World));	\n";
			}

			for (size_t i = 0; i < ServerClientMessage.size(); i++)
			{
				DisText += "	Dis.AddHandler(MessageId::" + ServerClientMessage[i].Name + ", std::bind(&OnMessageProcess<ThreadHandler" + ServerClientMessage[i].Name + "Message, " + ServerClientMessage[i].Name + "Message>, std::placeholders::_1, Inst, World));	\n";
			}
			DisText += "}																																													\n";

			std::string SavePath = SaveDir.PathToPlusFileName("Handler\\HandlerHeader.h");
			//GameServerFile SaveFile = GameServerFile{ SavePath, "wt" };
			//SaveFile.Write(DisText.c_str(), DisText.size());

			CopyList.push_back({ SavePath , DisText });
		}
	}

	for (int i = 0; i < CopyList.size(); ++i)
	{
		GameServerFile SaveFile = GameServerFile{ CopyList[i].SavePath, "wt"};
		SaveFile.Write(CopyList[i].Code.c_str(), CopyList[i].Code.size());
	}
	
	return 0;

}
