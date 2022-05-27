// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef UNREALCLIENT_LobbyGameMode_generated_h
#error "LobbyGameMode.generated.h already included, missing '#pragma once' in LobbyGameMode.h"
#endif
#define UNREALCLIENT_LobbyGameMode_generated_h

#define Unreal_Source_UnrealClient_Lobby_LobbyGameMode_h_15_SPARSE_DATA
#define Unreal_Source_UnrealClient_Lobby_LobbyGameMode_h_15_RPC_WRAPPERS
#define Unreal_Source_UnrealClient_Lobby_LobbyGameMode_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define Unreal_Source_UnrealClient_Lobby_LobbyGameMode_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesALobbyGameMode(); \
	friend struct Z_Construct_UClass_ALobbyGameMode_Statics; \
public: \
	DECLARE_CLASS(ALobbyGameMode, AGameMode, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/UnrealClient"), NO_API) \
	DECLARE_SERIALIZER(ALobbyGameMode)


#define Unreal_Source_UnrealClient_Lobby_LobbyGameMode_h_15_INCLASS \
private: \
	static void StaticRegisterNativesALobbyGameMode(); \
	friend struct Z_Construct_UClass_ALobbyGameMode_Statics; \
public: \
	DECLARE_CLASS(ALobbyGameMode, AGameMode, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/UnrealClient"), NO_API) \
	DECLARE_SERIALIZER(ALobbyGameMode)


#define Unreal_Source_UnrealClient_Lobby_LobbyGameMode_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ALobbyGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ALobbyGameMode) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ALobbyGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ALobbyGameMode); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ALobbyGameMode(ALobbyGameMode&&); \
	NO_API ALobbyGameMode(const ALobbyGameMode&); \
public:


#define Unreal_Source_UnrealClient_Lobby_LobbyGameMode_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ALobbyGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ALobbyGameMode(ALobbyGameMode&&); \
	NO_API ALobbyGameMode(const ALobbyGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ALobbyGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ALobbyGameMode); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ALobbyGameMode)


#define Unreal_Source_UnrealClient_Lobby_LobbyGameMode_h_15_PRIVATE_PROPERTY_OFFSET
#define Unreal_Source_UnrealClient_Lobby_LobbyGameMode_h_12_PROLOG
#define Unreal_Source_UnrealClient_Lobby_LobbyGameMode_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Unreal_Source_UnrealClient_Lobby_LobbyGameMode_h_15_PRIVATE_PROPERTY_OFFSET \
	Unreal_Source_UnrealClient_Lobby_LobbyGameMode_h_15_SPARSE_DATA \
	Unreal_Source_UnrealClient_Lobby_LobbyGameMode_h_15_RPC_WRAPPERS \
	Unreal_Source_UnrealClient_Lobby_LobbyGameMode_h_15_INCLASS \
	Unreal_Source_UnrealClient_Lobby_LobbyGameMode_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Unreal_Source_UnrealClient_Lobby_LobbyGameMode_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Unreal_Source_UnrealClient_Lobby_LobbyGameMode_h_15_PRIVATE_PROPERTY_OFFSET \
	Unreal_Source_UnrealClient_Lobby_LobbyGameMode_h_15_SPARSE_DATA \
	Unreal_Source_UnrealClient_Lobby_LobbyGameMode_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	Unreal_Source_UnrealClient_Lobby_LobbyGameMode_h_15_INCLASS_NO_PURE_DECLS \
	Unreal_Source_UnrealClient_Lobby_LobbyGameMode_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UNREALCLIENT_API UClass* StaticClass<class ALobbyGameMode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Unreal_Source_UnrealClient_Lobby_LobbyGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
