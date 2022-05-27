// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealClient/Packets/PacketComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePacketComponent() {}
// Cross Module References
	UNREALCLIENT_API UClass* Z_Construct_UClass_UPacketComponent_NoRegister();
	UNREALCLIENT_API UClass* Z_Construct_UClass_UPacketComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_UnrealClient();
// End Cross Module References
	void UPacketComponent::StaticRegisterNativesUPacketComponent()
	{
	}
	UClass* Z_Construct_UClass_UPacketComponent_NoRegister()
	{
		return UPacketComponent::StaticClass();
	}
	struct Z_Construct_UClass_UPacketComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPacketComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealClient,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPacketComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "Comment", "//??\xc5\xb6?? ?\xde\xbd??? ??????\xc6\xae???? ???????\xd3\xb8??? \xc6\xbd?? ???? \xc5\xa5???\xd6\xb4? ??\xc5\xb6?? \xc3\xb3??\n//???\xd3\xb8??\xe5\xbf\xa1 ?\xde\xbd?????????\xc6\xae?? ?\xdf\xb0?\n//(??\xc5\xb6?? \xc6\xbd???? \xc8\xae???\xcf\xbf? \xc3\xb3???\xd8\xbe??\xcf\xb1? ????,\n//\x09?????\xce\xbd??\xcf\xbd????? \xc6\xbd?\xd4\xbc??? ????\n//\x09?? ???\xd3\xb8??\xe5\xb8\xb6?? ?\xde\xbd??? ??????\xc6\xae?? ?\xdf\xb0??\xcf\xbf? \xc6\xbd???? \xc3\xb3??\n//\x09???\xd3\xb8????? \xc6\xbd?? ??\xc6\xbd???? \xc3\xb3?????? ????\n//)\n// \n// ???\xc3\xba? ??\xc5\xb6?? \xc3\xb3???\xcf\xb1? ???? ??\xc5\xb6 ??????\xc6\xae\n" },
		{ "IncludePath", "Packets/PacketComponent.h" },
		{ "ModuleRelativePath", "Packets/PacketComponent.h" },
		{ "ToolTip", "??\xc5\xb6?? ?\xde\xbd??? ??????\xc6\xae???? ???????\xd3\xb8??? \xc6\xbd?? ???? \xc5\xa5???\xd6\xb4? ??\xc5\xb6?? \xc3\xb3??\n???\xd3\xb8??\xe5\xbf\xa1 ?\xde\xbd?????????\xc6\xae?? ?\xdf\xb0?\n(??\xc5\xb6?? \xc6\xbd???? \xc8\xae???\xcf\xbf? \xc3\xb3???\xd8\xbe??\xcf\xb1? ????,\n       ?????\xce\xbd??\xcf\xbd????? \xc6\xbd?\xd4\xbc??? ????\n       ?? ???\xd3\xb8??\xe5\xb8\xb6?? ?\xde\xbd??? ??????\xc6\xae?? ?\xdf\xb0??\xcf\xbf? \xc6\xbd???? \xc3\xb3??\n       ???\xd3\xb8????? \xc6\xbd?? ??\xc6\xbd???? \xc3\xb3?????? ????\n)\n\n ???\xc3\xba? ??\xc5\xb6?? \xc3\xb3???\xcf\xb1? ???? ??\xc5\xb6 ??????\xc6\xae" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPacketComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPacketComponent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UPacketComponent_Statics::ClassParams = {
		&UPacketComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UPacketComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UPacketComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPacketComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UPacketComponent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPacketComponent, 3744388790);
	template<> UNREALCLIENT_API UClass* StaticClass<UPacketComponent>()
	{
		return UPacketComponent::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPacketComponent(Z_Construct_UClass_UPacketComponent, &UPacketComponent::StaticClass, TEXT("/Script/UnrealClient"), TEXT("UPacketComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPacketComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
