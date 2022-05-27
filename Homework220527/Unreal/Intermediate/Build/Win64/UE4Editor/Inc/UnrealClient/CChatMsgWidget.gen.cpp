// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealClient/Play/Chat/CChatMsgWidget.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCChatMsgWidget() {}
// Cross Module References
	UNREALCLIENT_API UClass* Z_Construct_UClass_UCChatMsgWidget_NoRegister();
	UNREALCLIENT_API UClass* Z_Construct_UClass_UCChatMsgWidget();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_UnrealClient();
// End Cross Module References
	void UCChatMsgWidget::StaticRegisterNativesUCChatMsgWidget()
	{
	}
	UClass* Z_Construct_UClass_UCChatMsgWidget_NoRegister()
	{
		return UCChatMsgWidget::StaticClass();
	}
	struct Z_Construct_UClass_UCChatMsgWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Message;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCChatMsgWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealClient,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCChatMsgWidget_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Play/Chat/CChatMsgWidget.h" },
		{ "ModuleRelativePath", "Play/Chat/CChatMsgWidget.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCChatMsgWidget_Statics::NewProp_Message_MetaData[] = {
		{ "Category", "ChatMessage" },
		{ "ModuleRelativePath", "Play/Chat/CChatMsgWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UCChatMsgWidget_Statics::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCChatMsgWidget, Message), METADATA_PARAMS(Z_Construct_UClass_UCChatMsgWidget_Statics::NewProp_Message_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCChatMsgWidget_Statics::NewProp_Message_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCChatMsgWidget_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCChatMsgWidget_Statics::NewProp_Message,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCChatMsgWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCChatMsgWidget>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UCChatMsgWidget_Statics::ClassParams = {
		&UCChatMsgWidget::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UCChatMsgWidget_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UCChatMsgWidget_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UCChatMsgWidget_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCChatMsgWidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCChatMsgWidget()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UCChatMsgWidget_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UCChatMsgWidget, 3809473126);
	template<> UNREALCLIENT_API UClass* StaticClass<UCChatMsgWidget>()
	{
		return UCChatMsgWidget::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UCChatMsgWidget(Z_Construct_UClass_UCChatMsgWidget, &UCChatMsgWidget::StaticClass, TEXT("/Script/UnrealClient"), TEXT("UCChatMsgWidget"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCChatMsgWidget);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
