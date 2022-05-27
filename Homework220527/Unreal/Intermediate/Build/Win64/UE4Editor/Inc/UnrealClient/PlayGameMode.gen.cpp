// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealClient/Play/PlayGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePlayGameMode() {}
// Cross Module References
	UNREALCLIENT_API UClass* Z_Construct_UClass_APlayGameMode_NoRegister();
	UNREALCLIENT_API UClass* Z_Construct_UClass_APlayGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameMode();
	UPackage* Z_Construct_UPackage__Script_UnrealClient();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	UNREALCLIENT_API UClass* Z_Construct_UClass_AClientCharacter_NoRegister();
// End Cross Module References
	void APlayGameMode::StaticRegisterNativesAPlayGameMode()
	{
	}
	UClass* Z_Construct_UClass_APlayGameMode_NoRegister()
	{
		return APlayGameMode::StaticClass();
	}
	struct Z_Construct_UClass_APlayGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OtherPlayerClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_OtherPlayerClass;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APlayGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameMode,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealClient,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APlayGameMode_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "Play/PlayGameMode.h" },
		{ "ModuleRelativePath", "Play/PlayGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APlayGameMode_Statics::NewProp_OtherPlayerClass_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "ClientData" },
		{ "Comment", "// OtherCharacter?? ?????\xcf\xb1? ???? \xc5\xac????\n" },
		{ "ModuleRelativePath", "Play/PlayGameMode.h" },
		{ "ToolTip", "OtherCharacter?? ?????\xcf\xb1? ???? \xc5\xac????" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_APlayGameMode_Statics::NewProp_OtherPlayerClass = { "OtherPlayerClass", nullptr, (EPropertyFlags)0x0044000000000005, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APlayGameMode, OtherPlayerClass), Z_Construct_UClass_AClientCharacter_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_APlayGameMode_Statics::NewProp_OtherPlayerClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APlayGameMode_Statics::NewProp_OtherPlayerClass_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APlayGameMode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayGameMode_Statics::NewProp_OtherPlayerClass,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_APlayGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APlayGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APlayGameMode_Statics::ClassParams = {
		&APlayGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_APlayGameMode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_APlayGameMode_Statics::PropPointers),
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_APlayGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APlayGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APlayGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APlayGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APlayGameMode, 3223809011);
	template<> UNREALCLIENT_API UClass* StaticClass<APlayGameMode>()
	{
		return APlayGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APlayGameMode(Z_Construct_UClass_APlayGameMode, &APlayGameMode::StaticClass, TEXT("/Script/UnrealClient"), TEXT("APlayGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APlayGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
