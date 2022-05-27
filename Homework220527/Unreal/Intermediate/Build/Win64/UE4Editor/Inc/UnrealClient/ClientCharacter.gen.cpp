// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealClient/Play/Character/ClientCharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeClientCharacter() {}
// Cross Module References
	UNREALCLIENT_API UClass* Z_Construct_UClass_AClientCharacter_NoRegister();
	UNREALCLIENT_API UClass* Z_Construct_UClass_AClientCharacter();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_UnrealClient();
	ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
	UNREALCLIENT_API UEnum* Z_Construct_UEnum_UnrealClient_ClientAnimationType();
// End Cross Module References
	void AClientCharacter::StaticRegisterNativesAClientCharacter()
	{
	}
	UClass* Z_Construct_UClass_AClientCharacter_NoRegister()
	{
		return AClientCharacter::StaticClass();
	}
	struct Z_Construct_UClass_AClientCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_m_Animations_ValueProp;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_m_Animations_Key_KeyProp_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_m_Animations_Key_KeyProp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_Animations_MetaData[];
#endif
		static const UE4CodeGen_Private::FMapPropertyParams NewProp_m_Animations;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AClientCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealClient,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AClientCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Play/Character/ClientCharacter.h" },
		{ "ModuleRelativePath", "Play/Character/ClientCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AClientCharacter_Statics::NewProp_m_Animations_ValueProp = { "m_Animations", nullptr, (EPropertyFlags)0x0000000000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_AClientCharacter_Statics::NewProp_m_Animations_Key_KeyProp_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AClientCharacter_Statics::NewProp_m_Animations_Key_KeyProp = { "m_Animations_Key", nullptr, (EPropertyFlags)0x0000000000000001, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UEnum_UnrealClient_ClientAnimationType, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AClientCharacter_Statics::NewProp_m_Animations_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "ClientData" },
		{ "ModuleRelativePath", "Play/Character/ClientCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FMapPropertyParams Z_Construct_UClass_AClientCharacter_Statics::NewProp_m_Animations = { "m_Animations", nullptr, (EPropertyFlags)0x0040000000000005, UE4CodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AClientCharacter, m_Animations), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_AClientCharacter_Statics::NewProp_m_Animations_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AClientCharacter_Statics::NewProp_m_Animations_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AClientCharacter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AClientCharacter_Statics::NewProp_m_Animations_ValueProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AClientCharacter_Statics::NewProp_m_Animations_Key_KeyProp_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AClientCharacter_Statics::NewProp_m_Animations_Key_KeyProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AClientCharacter_Statics::NewProp_m_Animations,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AClientCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AClientCharacter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AClientCharacter_Statics::ClassParams = {
		&AClientCharacter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AClientCharacter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AClientCharacter_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AClientCharacter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AClientCharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AClientCharacter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AClientCharacter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AClientCharacter, 4040304431);
	template<> UNREALCLIENT_API UClass* StaticClass<AClientCharacter>()
	{
		return AClientCharacter::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AClientCharacter(Z_Construct_UClass_AClientCharacter, &AClientCharacter::StaticClass, TEXT("/Script/UnrealClient"), TEXT("AClientCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AClientCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
