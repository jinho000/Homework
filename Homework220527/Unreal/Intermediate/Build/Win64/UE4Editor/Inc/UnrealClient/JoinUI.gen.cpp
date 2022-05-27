// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealClient/Login/JoinUI.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeJoinUI() {}
// Cross Module References
	UNREALCLIENT_API UClass* Z_Construct_UClass_UJoinUI_NoRegister();
	UNREALCLIENT_API UClass* Z_Construct_UClass_UJoinUI();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_UnrealClient();
// End Cross Module References
	DEFINE_FUNCTION(UJoinUI::execJoin)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->Join();
		P_NATIVE_END;
	}
	void UJoinUI::StaticRegisterNativesUJoinUI()
	{
		UClass* Class = UJoinUI::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Join", &UJoinUI::execJoin },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UJoinUI_Join_Statics
	{
		struct JoinUI_eventJoin_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UJoinUI_Join_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((JoinUI_eventJoin_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UJoinUI_Join_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(JoinUI_eventJoin_Parms), &Z_Construct_UFunction_UJoinUI_Join_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UJoinUI_Join_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UJoinUI_Join_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UJoinUI_Join_Statics::Function_MetaDataParams[] = {
		{ "Category", "JoinInfo" },
		{ "ModuleRelativePath", "Login/JoinUI.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UJoinUI_Join_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UJoinUI, nullptr, "Join", nullptr, nullptr, sizeof(JoinUI_eventJoin_Parms), Z_Construct_UFunction_UJoinUI_Join_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UJoinUI_Join_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UJoinUI_Join_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UJoinUI_Join_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UJoinUI_Join()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UJoinUI_Join_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UJoinUI_NoRegister()
	{
		return UJoinUI::StaticClass();
	}
	struct Z_Construct_UClass_UJoinUI_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ID_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ID;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Password_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Password;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_JoinState_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_JoinState;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UJoinUI_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealClient,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UJoinUI_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UJoinUI_Join, "Join" }, // 1530302427
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UJoinUI_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Login/JoinUI.h" },
		{ "ModuleRelativePath", "Login/JoinUI.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UJoinUI_Statics::NewProp_ID_MetaData[] = {
		{ "Category", "JoinInfo" },
		{ "ModuleRelativePath", "Login/JoinUI.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UJoinUI_Statics::NewProp_ID = { "ID", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UJoinUI, ID), METADATA_PARAMS(Z_Construct_UClass_UJoinUI_Statics::NewProp_ID_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UJoinUI_Statics::NewProp_ID_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UJoinUI_Statics::NewProp_Password_MetaData[] = {
		{ "Category", "JoinInfo" },
		{ "ModuleRelativePath", "Login/JoinUI.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UJoinUI_Statics::NewProp_Password = { "Password", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UJoinUI, Password), METADATA_PARAMS(Z_Construct_UClass_UJoinUI_Statics::NewProp_Password_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UJoinUI_Statics::NewProp_Password_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UJoinUI_Statics::NewProp_JoinState_MetaData[] = {
		{ "Category", "JoinInfo" },
		{ "ModuleRelativePath", "Login/JoinUI.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UJoinUI_Statics::NewProp_JoinState = { "JoinState", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UJoinUI, JoinState), METADATA_PARAMS(Z_Construct_UClass_UJoinUI_Statics::NewProp_JoinState_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UJoinUI_Statics::NewProp_JoinState_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UJoinUI_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJoinUI_Statics::NewProp_ID,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJoinUI_Statics::NewProp_Password,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UJoinUI_Statics::NewProp_JoinState,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UJoinUI_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UJoinUI>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UJoinUI_Statics::ClassParams = {
		&UJoinUI::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UJoinUI_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UJoinUI_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UJoinUI_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UJoinUI_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UJoinUI()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UJoinUI_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UJoinUI, 782703433);
	template<> UNREALCLIENT_API UClass* StaticClass<UJoinUI>()
	{
		return UJoinUI::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UJoinUI(Z_Construct_UClass_UJoinUI, &UJoinUI::StaticClass, TEXT("/Script/UnrealClient"), TEXT("UJoinUI"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UJoinUI);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
