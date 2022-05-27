// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealClient/Play/Chat/CChatMessage.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCChatMessage() {}
// Cross Module References
	UNREALCLIENT_API UClass* Z_Construct_UClass_UCChatMessage_NoRegister();
	UNREALCLIENT_API UClass* Z_Construct_UClass_UCChatMessage();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_UnrealClient();
// End Cross Module References
	void UCChatMessage::StaticRegisterNativesUCChatMessage()
	{
	}
	UClass* Z_Construct_UClass_UCChatMessage_NoRegister()
	{
		return UCChatMessage::StaticClass();
	}
	struct Z_Construct_UClass_UCChatMessage_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCChatMessage_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealClient,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCChatMessage_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Play/Chat/CChatMessage.h" },
		{ "ModuleRelativePath", "Play/Chat/CChatMessage.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCChatMessage_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCChatMessage>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UCChatMessage_Statics::ClassParams = {
		&UCChatMessage::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UCChatMessage_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCChatMessage_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCChatMessage()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UCChatMessage_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UCChatMessage, 3749544737);
	template<> UNREALCLIENT_API UClass* StaticClass<UCChatMessage>()
	{
		return UCChatMessage::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UCChatMessage(Z_Construct_UClass_UCChatMessage, &UCChatMessage::StaticClass, TEXT("/Script/UnrealClient"), TEXT("UCChatMessage"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCChatMessage);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
