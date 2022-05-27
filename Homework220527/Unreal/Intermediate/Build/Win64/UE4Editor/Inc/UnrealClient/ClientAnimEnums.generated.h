// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef UNREALCLIENT_ClientAnimEnums_generated_h
#error "ClientAnimEnums.generated.h already included, missing '#pragma once' in ClientAnimEnums.h"
#endif
#define UNREALCLIENT_ClientAnimEnums_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Unreal_Source_UnrealClient_Play_Character_ClientAnimEnums_h


#define FOREACH_ENUM_CLIENTANIMATIONTYPE(op) \
	op(ClientAnimationType::NONE) \
	op(ClientAnimationType::Idle) \
	op(ClientAnimationType::Move) \
	op(ClientAnimationType::Attack) 

enum class ClientAnimationType : uint8;
template<> UNREALCLIENT_API UEnum* StaticEnum<ClientAnimationType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
