// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef UNREALCLIENT_CLoginUI_generated_h
#error "CLoginUI.generated.h already included, missing '#pragma once' in CLoginUI.h"
#endif
#define UNREALCLIENT_CLoginUI_generated_h

#define Unreal_Source_UnrealClient_Login_CLoginUI_h_21_SPARSE_DATA
#define Unreal_Source_UnrealClient_Login_CLoginUI_h_21_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execPressJoinBtn); \
	DECLARE_FUNCTION(execLogin); \
	DECLARE_FUNCTION(execConnectServer); \
	DECLARE_FUNCTION(execResetConnectInfo);


#define Unreal_Source_UnrealClient_Login_CLoginUI_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execPressJoinBtn); \
	DECLARE_FUNCTION(execLogin); \
	DECLARE_FUNCTION(execConnectServer); \
	DECLARE_FUNCTION(execResetConnectInfo);


#define Unreal_Source_UnrealClient_Login_CLoginUI_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCLoginUI(); \
	friend struct Z_Construct_UClass_UCLoginUI_Statics; \
public: \
	DECLARE_CLASS(UCLoginUI, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UnrealClient"), NO_API) \
	DECLARE_SERIALIZER(UCLoginUI)


#define Unreal_Source_UnrealClient_Login_CLoginUI_h_21_INCLASS \
private: \
	static void StaticRegisterNativesUCLoginUI(); \
	friend struct Z_Construct_UClass_UCLoginUI_Statics; \
public: \
	DECLARE_CLASS(UCLoginUI, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UnrealClient"), NO_API) \
	DECLARE_SERIALIZER(UCLoginUI)


#define Unreal_Source_UnrealClient_Login_CLoginUI_h_21_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCLoginUI(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCLoginUI) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCLoginUI); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCLoginUI); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCLoginUI(UCLoginUI&&); \
	NO_API UCLoginUI(const UCLoginUI&); \
public:


#define Unreal_Source_UnrealClient_Login_CLoginUI_h_21_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCLoginUI(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCLoginUI(UCLoginUI&&); \
	NO_API UCLoginUI(const UCLoginUI&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCLoginUI); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCLoginUI); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCLoginUI)


#define Unreal_Source_UnrealClient_Login_CLoginUI_h_21_PRIVATE_PROPERTY_OFFSET
#define Unreal_Source_UnrealClient_Login_CLoginUI_h_17_PROLOG
#define Unreal_Source_UnrealClient_Login_CLoginUI_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Unreal_Source_UnrealClient_Login_CLoginUI_h_21_PRIVATE_PROPERTY_OFFSET \
	Unreal_Source_UnrealClient_Login_CLoginUI_h_21_SPARSE_DATA \
	Unreal_Source_UnrealClient_Login_CLoginUI_h_21_RPC_WRAPPERS \
	Unreal_Source_UnrealClient_Login_CLoginUI_h_21_INCLASS \
	Unreal_Source_UnrealClient_Login_CLoginUI_h_21_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Unreal_Source_UnrealClient_Login_CLoginUI_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Unreal_Source_UnrealClient_Login_CLoginUI_h_21_PRIVATE_PROPERTY_OFFSET \
	Unreal_Source_UnrealClient_Login_CLoginUI_h_21_SPARSE_DATA \
	Unreal_Source_UnrealClient_Login_CLoginUI_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	Unreal_Source_UnrealClient_Login_CLoginUI_h_21_INCLASS_NO_PURE_DECLS \
	Unreal_Source_UnrealClient_Login_CLoginUI_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UNREALCLIENT_API UClass* StaticClass<class UCLoginUI>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Unreal_Source_UnrealClient_Login_CLoginUI_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
