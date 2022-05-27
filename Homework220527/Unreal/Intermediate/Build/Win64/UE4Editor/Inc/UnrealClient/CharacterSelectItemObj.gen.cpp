// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealClient/CharacterSelect/CharacterSelectItemObj.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCharacterSelectItemObj() {}
// Cross Module References
	UNREALCLIENT_API UClass* Z_Construct_UClass_UCharacterSelectItemObj_NoRegister();
	UNREALCLIENT_API UClass* Z_Construct_UClass_UCharacterSelectItemObj();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_UnrealClient();
// End Cross Module References
	void UCharacterSelectItemObj::StaticRegisterNativesUCharacterSelectItemObj()
	{
	}
	UClass* Z_Construct_UClass_UCharacterSelectItemObj_NoRegister()
	{
		return UCharacterSelectItemObj::StaticClass();
	}
	struct Z_Construct_UClass_UCharacterSelectItemObj_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCharacterSelectItemObj_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealClient,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCharacterSelectItemObj_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "CharacterSelect/CharacterSelectItemObj.h" },
		{ "ModuleRelativePath", "CharacterSelect/CharacterSelectItemObj.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCharacterSelectItemObj_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCharacterSelectItemObj>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UCharacterSelectItemObj_Statics::ClassParams = {
		&UCharacterSelectItemObj::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UCharacterSelectItemObj_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCharacterSelectItemObj_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCharacterSelectItemObj()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UCharacterSelectItemObj_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UCharacterSelectItemObj, 1239887568);
	template<> UNREALCLIENT_API UClass* StaticClass<UCharacterSelectItemObj>()
	{
		return UCharacterSelectItemObj::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UCharacterSelectItemObj(Z_Construct_UClass_UCharacterSelectItemObj, &UCharacterSelectItemObj::StaticClass, TEXT("/Script/UnrealClient"), TEXT("UCharacterSelectItemObj"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCharacterSelectItemObj);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
