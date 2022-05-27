// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealClient/Lobby/LobbyUI.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLobbyUI() {}
// Cross Module References
	UNREALCLIENT_API UClass* Z_Construct_UClass_ULobbyUI_NoRegister();
	UNREALCLIENT_API UClass* Z_Construct_UClass_ULobbyUI();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_UnrealClient();
// End Cross Module References
	DEFINE_FUNCTION(ULobbyUI::execCancel)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Cancel();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ULobbyUI::execRequestGameMatch)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RequestGameMatch();
		P_NATIVE_END;
	}
	void ULobbyUI::StaticRegisterNativesULobbyUI()
	{
		UClass* Class = ULobbyUI::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Cancel", &ULobbyUI::execCancel },
			{ "RequestGameMatch", &ULobbyUI::execRequestGameMatch },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ULobbyUI_Cancel_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULobbyUI_Cancel_Statics::Function_MetaDataParams[] = {
		{ "Category", "Lobby" },
		{ "ModuleRelativePath", "Lobby/LobbyUI.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULobbyUI_Cancel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULobbyUI, nullptr, "Cancel", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULobbyUI_Cancel_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ULobbyUI_Cancel_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULobbyUI_Cancel()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULobbyUI_Cancel_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULobbyUI_RequestGameMatch_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULobbyUI_RequestGameMatch_Statics::Function_MetaDataParams[] = {
		{ "Category", "Lobby" },
		{ "Comment", "// UFUNCTION: ????????\xc6\xae???? ?\xd4\xbc??? ?????\xcf\xb1? ???? ????\n" },
		{ "ModuleRelativePath", "Lobby/LobbyUI.h" },
		{ "ToolTip", "UFUNCTION: ????????\xc6\xae???? ?\xd4\xbc??? ?????\xcf\xb1? ???? ????" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULobbyUI_RequestGameMatch_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULobbyUI, nullptr, "RequestGameMatch", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULobbyUI_RequestGameMatch_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ULobbyUI_RequestGameMatch_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULobbyUI_RequestGameMatch()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULobbyUI_RequestGameMatch_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ULobbyUI_NoRegister()
	{
		return ULobbyUI::StaticClass();
	}
	struct Z_Construct_UClass_ULobbyUI_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ULobbyUI_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealClient,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ULobbyUI_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ULobbyUI_Cancel, "Cancel" }, // 1258237953
		{ &Z_Construct_UFunction_ULobbyUI_RequestGameMatch, "RequestGameMatch" }, // 680810439
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULobbyUI_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Lobby/LobbyUI.h" },
		{ "ModuleRelativePath", "Lobby/LobbyUI.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ULobbyUI_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULobbyUI>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ULobbyUI_Statics::ClassParams = {
		&ULobbyUI::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_ULobbyUI_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ULobbyUI_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ULobbyUI()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ULobbyUI_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ULobbyUI, 3907341528);
	template<> UNREALCLIENT_API UClass* StaticClass<ULobbyUI>()
	{
		return ULobbyUI::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ULobbyUI(Z_Construct_UClass_ULobbyUI, &ULobbyUI::StaticClass, TEXT("/Script/UnrealClient"), TEXT("ULobbyUI"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ULobbyUI);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
