// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealClient/CharacterSelect/CharacterSelectUI.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCharacterSelectUI() {}
// Cross Module References
	UNREALCLIENT_API UClass* Z_Construct_UClass_UCharacterSelectUI_NoRegister();
	UNREALCLIENT_API UClass* Z_Construct_UClass_UCharacterSelectUI();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_UnrealClient();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UListView_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UCharacterSelectUI::execAddItemToListEvent)
	{
		P_GET_OBJECT(UObject,Z_Param__Object);
		P_GET_OBJECT(UUserWidget,Z_Param__Widget);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddItemToListEvent(Z_Param__Object,Z_Param__Widget);
		P_NATIVE_END;
	}
	void UCharacterSelectUI::StaticRegisterNativesUCharacterSelectUI()
	{
		UClass* Class = UCharacterSelectUI::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddItemToListEvent", &UCharacterSelectUI::execAddItemToListEvent },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UCharacterSelectUI_AddItemToListEvent_Statics
	{
		struct CharacterSelectUI_eventAddItemToListEvent_Parms
		{
			UObject* _Object;
			UUserWidget* _Widget;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp__Object;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__Widget_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp__Widget;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCharacterSelectUI_AddItemToListEvent_Statics::NewProp__Object = { "_Object", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CharacterSelectUI_eventAddItemToListEvent_Parms, _Object), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCharacterSelectUI_AddItemToListEvent_Statics::NewProp__Widget_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCharacterSelectUI_AddItemToListEvent_Statics::NewProp__Widget = { "_Widget", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CharacterSelectUI_eventAddItemToListEvent_Parms, _Widget), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UCharacterSelectUI_AddItemToListEvent_Statics::NewProp__Widget_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCharacterSelectUI_AddItemToListEvent_Statics::NewProp__Widget_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCharacterSelectUI_AddItemToListEvent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCharacterSelectUI_AddItemToListEvent_Statics::NewProp__Object,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCharacterSelectUI_AddItemToListEvent_Statics::NewProp__Widget,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCharacterSelectUI_AddItemToListEvent_Statics::Function_MetaDataParams[] = {
		{ "Category", "CharaterSelectUI" },
		{ "Comment", "// UFUNCTION: ????????\xc6\xae???? ?\xd4\xbc??? ?????\xcf\xb1? ???? ????\n" },
		{ "ModuleRelativePath", "CharacterSelect/CharacterSelectUI.h" },
		{ "ToolTip", "UFUNCTION: ????????\xc6\xae???? ?\xd4\xbc??? ?????\xcf\xb1? ???? ????" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UCharacterSelectUI_AddItemToListEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCharacterSelectUI, nullptr, "AddItemToListEvent", nullptr, nullptr, sizeof(CharacterSelectUI_eventAddItemToListEvent_Parms), Z_Construct_UFunction_UCharacterSelectUI_AddItemToListEvent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCharacterSelectUI_AddItemToListEvent_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCharacterSelectUI_AddItemToListEvent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCharacterSelectUI_AddItemToListEvent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCharacterSelectUI_AddItemToListEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UCharacterSelectUI_AddItemToListEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UCharacterSelectUI_NoRegister()
	{
		return UCharacterSelectUI::StaticClass();
	}
	struct Z_Construct_UClass_UCharacterSelectUI_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CharacterListView_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CharacterListView;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_State_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_State;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCharacterSelectUI_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealClient,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UCharacterSelectUI_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UCharacterSelectUI_AddItemToListEvent, "AddItemToListEvent" }, // 3689762912
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCharacterSelectUI_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "CharacterSelect/CharacterSelectUI.h" },
		{ "ModuleRelativePath", "CharacterSelect/CharacterSelectUI.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCharacterSelectUI_Statics::NewProp_CharacterListView_MetaData[] = {
		{ "Category", "CharaterSelectUI" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "CharacterSelect/CharacterSelectUI.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCharacterSelectUI_Statics::NewProp_CharacterListView = { "CharacterListView", nullptr, (EPropertyFlags)0x001000000008000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCharacterSelectUI, CharacterListView), Z_Construct_UClass_UListView_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UCharacterSelectUI_Statics::NewProp_CharacterListView_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCharacterSelectUI_Statics::NewProp_CharacterListView_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCharacterSelectUI_Statics::NewProp_State_MetaData[] = {
		{ "Category", "CharaterSelectUI" },
		{ "ModuleRelativePath", "CharacterSelect/CharacterSelectUI.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UCharacterSelectUI_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCharacterSelectUI, State), METADATA_PARAMS(Z_Construct_UClass_UCharacterSelectUI_Statics::NewProp_State_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCharacterSelectUI_Statics::NewProp_State_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCharacterSelectUI_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCharacterSelectUI_Statics::NewProp_CharacterListView,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCharacterSelectUI_Statics::NewProp_State,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCharacterSelectUI_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCharacterSelectUI>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UCharacterSelectUI_Statics::ClassParams = {
		&UCharacterSelectUI::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UCharacterSelectUI_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UCharacterSelectUI_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UCharacterSelectUI_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCharacterSelectUI_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCharacterSelectUI()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UCharacterSelectUI_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UCharacterSelectUI, 3683198682);
	template<> UNREALCLIENT_API UClass* StaticClass<UCharacterSelectUI>()
	{
		return UCharacterSelectUI::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UCharacterSelectUI(Z_Construct_UClass_UCharacterSelectUI, &UCharacterSelectUI::StaticClass, TEXT("/Script/UnrealClient"), TEXT("UCharacterSelectUI"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCharacterSelectUI);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif