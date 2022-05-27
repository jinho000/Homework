// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef UNREALCLIENT_PlayGameMode_generated_h
#error "PlayGameMode.generated.h already included, missing '#pragma once' in PlayGameMode.h"
#endif
#define UNREALCLIENT_PlayGameMode_generated_h

#define Unreal_Source_UnrealClient_Play_PlayGameMode_h_19_SPARSE_DATA
#define Unreal_Source_UnrealClient_Play_PlayGameMode_h_19_RPC_WRAPPERS
#define Unreal_Source_UnrealClient_Play_PlayGameMode_h_19_RPC_WRAPPERS_NO_PURE_DECLS
#define Unreal_Source_UnrealClient_Play_PlayGameMode_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPlayGameMode(); \
	friend struct Z_Construct_UClass_APlayGameMode_Statics; \
public: \
	DECLARE_CLASS(APlayGameMode, AGameMode, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/UnrealClient"), NO_API) \
	DECLARE_SERIALIZER(APlayGameMode)


#define Unreal_Source_UnrealClient_Play_PlayGameMode_h_19_INCLASS \
private: \
	static void StaticRegisterNativesAPlayGameMode(); \
	friend struct Z_Construct_UClass_APlayGameMode_Statics; \
public: \
	DECLARE_CLASS(APlayGameMode, AGameMode, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/UnrealClient"), NO_API) \
	DECLARE_SERIALIZER(APlayGameMode)


#define Unreal_Source_UnrealClient_Play_PlayGameMode_h_19_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APlayGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APlayGameMode) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlayGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlayGameMode); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APlayGameMode(APlayGameMode&&); \
	NO_API APlayGameMode(const APlayGameMode&); \
public:


#define Unreal_Source_UnrealClient_Play_PlayGameMode_h_19_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APlayGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APlayGameMode(APlayGameMode&&); \
	NO_API APlayGameMode(const APlayGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlayGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlayGameMode); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APlayGameMode)


#define Unreal_Source_UnrealClient_Play_PlayGameMode_h_19_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__OtherPlayerClass() { return STRUCT_OFFSET(APlayGameMode, OtherPlayerClass); }


#define Unreal_Source_UnrealClient_Play_PlayGameMode_h_16_PROLOG
#define Unreal_Source_UnrealClient_Play_PlayGameMode_h_19_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Unreal_Source_UnrealClient_Play_PlayGameMode_h_19_PRIVATE_PROPERTY_OFFSET \
	Unreal_Source_UnrealClient_Play_PlayGameMode_h_19_SPARSE_DATA \
	Unreal_Source_UnrealClient_Play_PlayGameMode_h_19_RPC_WRAPPERS \
	Unreal_Source_UnrealClient_Play_PlayGameMode_h_19_INCLASS \
	Unreal_Source_UnrealClient_Play_PlayGameMode_h_19_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Unreal_Source_UnrealClient_Play_PlayGameMode_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Unreal_Source_UnrealClient_Play_PlayGameMode_h_19_PRIVATE_PROPERTY_OFFSET \
	Unreal_Source_UnrealClient_Play_PlayGameMode_h_19_SPARSE_DATA \
	Unreal_Source_UnrealClient_Play_PlayGameMode_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	Unreal_Source_UnrealClient_Play_PlayGameMode_h_19_INCLASS_NO_PURE_DECLS \
	Unreal_Source_UnrealClient_Play_PlayGameMode_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UNREALCLIENT_API UClass* StaticClass<class APlayGameMode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Unreal_Source_UnrealClient_Play_PlayGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
