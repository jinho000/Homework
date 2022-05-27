// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
class UUserWidget;
#ifdef UNREALCLIENT_CChatWindow_generated_h
#error "CChatWindow.generated.h already included, missing '#pragma once' in CChatWindow.h"
#endif
#define UNREALCLIENT_CChatWindow_generated_h

#define Unreal_Source_UnrealClient_Play_Chat_CChatWindow_h_17_SPARSE_DATA
#define Unreal_Source_UnrealClient_Play_Chat_CChatWindow_h_17_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnChatMsgCommitted); \
	DECLARE_FUNCTION(execAddChatMessage);


#define Unreal_Source_UnrealClient_Play_Chat_CChatWindow_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnChatMsgCommitted); \
	DECLARE_FUNCTION(execAddChatMessage);


#define Unreal_Source_UnrealClient_Play_Chat_CChatWindow_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCChatWindow(); \
	friend struct Z_Construct_UClass_UCChatWindow_Statics; \
public: \
	DECLARE_CLASS(UCChatWindow, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UnrealClient"), NO_API) \
	DECLARE_SERIALIZER(UCChatWindow)


#define Unreal_Source_UnrealClient_Play_Chat_CChatWindow_h_17_INCLASS \
private: \
	static void StaticRegisterNativesUCChatWindow(); \
	friend struct Z_Construct_UClass_UCChatWindow_Statics; \
public: \
	DECLARE_CLASS(UCChatWindow, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UnrealClient"), NO_API) \
	DECLARE_SERIALIZER(UCChatWindow)


#define Unreal_Source_UnrealClient_Play_Chat_CChatWindow_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCChatWindow(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCChatWindow) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCChatWindow); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCChatWindow); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCChatWindow(UCChatWindow&&); \
	NO_API UCChatWindow(const UCChatWindow&); \
public:


#define Unreal_Source_UnrealClient_Play_Chat_CChatWindow_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCChatWindow(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCChatWindow(UCChatWindow&&); \
	NO_API UCChatWindow(const UCChatWindow&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCChatWindow); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCChatWindow); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCChatWindow)


#define Unreal_Source_UnrealClient_Play_Chat_CChatWindow_h_17_PRIVATE_PROPERTY_OFFSET
#define Unreal_Source_UnrealClient_Play_Chat_CChatWindow_h_14_PROLOG
#define Unreal_Source_UnrealClient_Play_Chat_CChatWindow_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Unreal_Source_UnrealClient_Play_Chat_CChatWindow_h_17_PRIVATE_PROPERTY_OFFSET \
	Unreal_Source_UnrealClient_Play_Chat_CChatWindow_h_17_SPARSE_DATA \
	Unreal_Source_UnrealClient_Play_Chat_CChatWindow_h_17_RPC_WRAPPERS \
	Unreal_Source_UnrealClient_Play_Chat_CChatWindow_h_17_INCLASS \
	Unreal_Source_UnrealClient_Play_Chat_CChatWindow_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Unreal_Source_UnrealClient_Play_Chat_CChatWindow_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Unreal_Source_UnrealClient_Play_Chat_CChatWindow_h_17_PRIVATE_PROPERTY_OFFSET \
	Unreal_Source_UnrealClient_Play_Chat_CChatWindow_h_17_SPARSE_DATA \
	Unreal_Source_UnrealClient_Play_Chat_CChatWindow_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	Unreal_Source_UnrealClient_Play_Chat_CChatWindow_h_17_INCLASS_NO_PURE_DECLS \
	Unreal_Source_UnrealClient_Play_Chat_CChatWindow_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UNREALCLIENT_API UClass* StaticClass<class UCChatWindow>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Unreal_Source_UnrealClient_Play_Chat_CChatWindow_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
