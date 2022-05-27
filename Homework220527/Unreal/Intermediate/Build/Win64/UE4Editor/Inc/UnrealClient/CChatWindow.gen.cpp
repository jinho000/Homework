// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealClient/Play/Chat/CChatWindow.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCChatWindow() {}
// Cross Module References
	UNREALCLIENT_API UClass* Z_Construct_UClass_UCChatWindow_NoRegister();
	UNREALCLIENT_API UClass* Z_Construct_UClass_UCChatWindow();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_UnrealClient();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
	SLATECORE_API UEnum* Z_Construct_UEnum_SlateCore_ETextCommit();
	UMG_API UClass* Z_Construct_UClass_UListView_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UCChatWindow::execOnChatMsgCommitted)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param__text);
		P_GET_PROPERTY(FByteProperty,Z_Param__commitType);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnChatMsgCommitted(Z_Param__text,ETextCommit::Type(Z_Param__commitType));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCChatWindow::execAddChatMessage)
	{
		P_GET_OBJECT(UObject,Z_Param__chatMsgObj);
		P_GET_OBJECT(UUserWidget,Z_Param__chatMsgWidget);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddChatMessage(Z_Param__chatMsgObj,Z_Param__chatMsgWidget);
		P_NATIVE_END;
	}
	void UCChatWindow::StaticRegisterNativesUCChatWindow()
	{
		UClass* Class = UCChatWindow::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddChatMessage", &UCChatWindow::execAddChatMessage },
			{ "OnChatMsgCommitted", &UCChatWindow::execOnChatMsgCommitted },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UCChatWindow_AddChatMessage_Statics
	{
		struct CChatWindow_eventAddChatMessage_Parms
		{
			UObject* _chatMsgObj;
			UUserWidget* _chatMsgWidget;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp__chatMsgObj;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__chatMsgWidget_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp__chatMsgWidget;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCChatWindow_AddChatMessage_Statics::NewProp__chatMsgObj = { "_chatMsgObj", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CChatWindow_eventAddChatMessage_Parms, _chatMsgObj), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCChatWindow_AddChatMessage_Statics::NewProp__chatMsgWidget_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCChatWindow_AddChatMessage_Statics::NewProp__chatMsgWidget = { "_chatMsgWidget", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CChatWindow_eventAddChatMessage_Parms, _chatMsgWidget), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UCChatWindow_AddChatMessage_Statics::NewProp__chatMsgWidget_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCChatWindow_AddChatMessage_Statics::NewProp__chatMsgWidget_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCChatWindow_AddChatMessage_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCChatWindow_AddChatMessage_Statics::NewProp__chatMsgObj,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCChatWindow_AddChatMessage_Statics::NewProp__chatMsgWidget,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCChatWindow_AddChatMessage_Statics::Function_MetaDataParams[] = {
		{ "Category", "Chatting" },
		{ "ModuleRelativePath", "Play/Chat/CChatWindow.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UCChatWindow_AddChatMessage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCChatWindow, nullptr, "AddChatMessage", nullptr, nullptr, sizeof(CChatWindow_eventAddChatMessage_Parms), Z_Construct_UFunction_UCChatWindow_AddChatMessage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCChatWindow_AddChatMessage_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCChatWindow_AddChatMessage_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCChatWindow_AddChatMessage_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCChatWindow_AddChatMessage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UCChatWindow_AddChatMessage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCChatWindow_OnChatMsgCommitted_Statics
	{
		struct CChatWindow_eventOnChatMsgCommitted_Parms
		{
			FString _text;
			TEnumAsByte<ETextCommit::Type> _commitType;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__text_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp__text;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp__commitType;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCChatWindow_OnChatMsgCommitted_Statics::NewProp__text_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UCChatWindow_OnChatMsgCommitted_Statics::NewProp__text = { "_text", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CChatWindow_eventOnChatMsgCommitted_Parms, _text), METADATA_PARAMS(Z_Construct_UFunction_UCChatWindow_OnChatMsgCommitted_Statics::NewProp__text_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCChatWindow_OnChatMsgCommitted_Statics::NewProp__text_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCChatWindow_OnChatMsgCommitted_Statics::NewProp__commitType = { "_commitType", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CChatWindow_eventOnChatMsgCommitted_Parms, _commitType), Z_Construct_UEnum_SlateCore_ETextCommit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCChatWindow_OnChatMsgCommitted_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCChatWindow_OnChatMsgCommitted_Statics::NewProp__text,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCChatWindow_OnChatMsgCommitted_Statics::NewProp__commitType,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCChatWindow_OnChatMsgCommitted_Statics::Function_MetaDataParams[] = {
		{ "Category", "Chatting" },
		{ "ModuleRelativePath", "Play/Chat/CChatWindow.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UCChatWindow_OnChatMsgCommitted_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCChatWindow, nullptr, "OnChatMsgCommitted", nullptr, nullptr, sizeof(CChatWindow_eventOnChatMsgCommitted_Parms), Z_Construct_UFunction_UCChatWindow_OnChatMsgCommitted_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCChatWindow_OnChatMsgCommitted_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCChatWindow_OnChatMsgCommitted_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCChatWindow_OnChatMsgCommitted_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCChatWindow_OnChatMsgCommitted()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UCChatWindow_OnChatMsgCommitted_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UCChatWindow_NoRegister()
	{
		return UCChatWindow::StaticClass();
	}
	struct Z_Construct_UClass_UCChatWindow_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MessageList_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MessageList;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InputText_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_InputText;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCChatWindow_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealClient,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UCChatWindow_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UCChatWindow_AddChatMessage, "AddChatMessage" }, // 1204262506
		{ &Z_Construct_UFunction_UCChatWindow_OnChatMsgCommitted, "OnChatMsgCommitted" }, // 2721932859
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCChatWindow_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Play/Chat/CChatWindow.h" },
		{ "ModuleRelativePath", "Play/Chat/CChatWindow.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCChatWindow_Statics::NewProp_MessageList_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "CChatWindow" },
		{ "Comment", "// ?????? ???? ???? (?????????? = ?????\xcc\xb8?)\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Play/Chat/CChatWindow.h" },
		{ "ToolTip", "?????? ???? ???? (?????????? = ?????\xcc\xb8?)" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCChatWindow_Statics::NewProp_MessageList = { "MessageList", nullptr, (EPropertyFlags)0x001000000008000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCChatWindow, MessageList), Z_Construct_UClass_UListView_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UCChatWindow_Statics::NewProp_MessageList_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCChatWindow_Statics::NewProp_MessageList_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCChatWindow_Statics::NewProp_InputText_MetaData[] = {
		{ "Category", "Chatting" },
		{ "Comment", "// ?\xd4\xb7? ?\xd8\xbd?\xc6\xae\n" },
		{ "ModuleRelativePath", "Play/Chat/CChatWindow.h" },
		{ "ToolTip", "?\xd4\xb7? ?\xd8\xbd?\xc6\xae" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UCChatWindow_Statics::NewProp_InputText = { "InputText", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCChatWindow, InputText), METADATA_PARAMS(Z_Construct_UClass_UCChatWindow_Statics::NewProp_InputText_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCChatWindow_Statics::NewProp_InputText_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCChatWindow_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCChatWindow_Statics::NewProp_MessageList,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCChatWindow_Statics::NewProp_InputText,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCChatWindow_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCChatWindow>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UCChatWindow_Statics::ClassParams = {
		&UCChatWindow::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UCChatWindow_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UCChatWindow_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UCChatWindow_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCChatWindow_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCChatWindow()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UCChatWindow_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UCChatWindow, 2109337737);
	template<> UNREALCLIENT_API UClass* StaticClass<UCChatWindow>()
	{
		return UCChatWindow::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UCChatWindow(Z_Construct_UClass_UCChatWindow, &UCChatWindow::StaticClass, TEXT("/Script/UnrealClient"), TEXT("UCChatWindow"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCChatWindow);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
