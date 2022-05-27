// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef UNREALCLIENT_LobbyUI_generated_h
#error "LobbyUI.generated.h already included, missing '#pragma once' in LobbyUI.h"
#endif
#define UNREALCLIENT_LobbyUI_generated_h

#define Unreal_Source_UnrealClient_Lobby_LobbyUI_h_15_SPARSE_DATA
#define Unreal_Source_UnrealClient_Lobby_LobbyUI_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execCancel); \
	DECLARE_FUNCTION(execRequestGameMatch);


#define Unreal_Source_UnrealClient_Lobby_LobbyUI_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execCancel); \
	DECLARE_FUNCTION(execRequestGameMatch);


#define Unreal_Source_UnrealClient_Lobby_LobbyUI_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULobbyUI(); \
	friend struct Z_Construct_UClass_ULobbyUI_Statics; \
public: \
	DECLARE_CLASS(ULobbyUI, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UnrealClient"), NO_API) \
	DECLARE_SERIALIZER(ULobbyUI)


#define Unreal_Source_UnrealClient_Lobby_LobbyUI_h_15_INCLASS \
private: \
	static void StaticRegisterNativesULobbyUI(); \
	friend struct Z_Construct_UClass_ULobbyUI_Statics; \
public: \
	DECLARE_CLASS(ULobbyUI, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UnrealClient"), NO_API) \
	DECLARE_SERIALIZER(ULobbyUI)


#define Unreal_Source_UnrealClient_Lobby_LobbyUI_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULobbyUI(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULobbyUI) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULobbyUI); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULobbyUI); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULobbyUI(ULobbyUI&&); \
	NO_API ULobbyUI(const ULobbyUI&); \
public:


#define Unreal_Source_UnrealClient_Lobby_LobbyUI_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULobbyUI(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULobbyUI(ULobbyUI&&); \
	NO_API ULobbyUI(const ULobbyUI&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULobbyUI); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULobbyUI); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULobbyUI)


#define Unreal_Source_UnrealClient_Lobby_LobbyUI_h_15_PRIVATE_PROPERTY_OFFSET
#define Unreal_Source_UnrealClient_Lobby_LobbyUI_h_12_PROLOG
#define Unreal_Source_UnrealClient_Lobby_LobbyUI_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Unreal_Source_UnrealClient_Lobby_LobbyUI_h_15_PRIVATE_PROPERTY_OFFSET \
	Unreal_Source_UnrealClient_Lobby_LobbyUI_h_15_SPARSE_DATA \
	Unreal_Source_UnrealClient_Lobby_LobbyUI_h_15_RPC_WRAPPERS \
	Unreal_Source_UnrealClient_Lobby_LobbyUI_h_15_INCLASS \
	Unreal_Source_UnrealClient_Lobby_LobbyUI_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Unreal_Source_UnrealClient_Lobby_LobbyUI_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Unreal_Source_UnrealClient_Lobby_LobbyUI_h_15_PRIVATE_PROPERTY_OFFSET \
	Unreal_Source_UnrealClient_Lobby_LobbyUI_h_15_SPARSE_DATA \
	Unreal_Source_UnrealClient_Lobby_LobbyUI_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	Unreal_Source_UnrealClient_Lobby_LobbyUI_h_15_INCLASS_NO_PURE_DECLS \
	Unreal_Source_UnrealClient_Lobby_LobbyUI_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UNREALCLIENT_API UClass* StaticClass<class ULobbyUI>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Unreal_Source_UnrealClient_Lobby_LobbyUI_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
