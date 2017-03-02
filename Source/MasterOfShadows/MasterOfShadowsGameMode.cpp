// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "MasterOfShadows.h"
#include "MasterOfShadowsGameMode.h"
#include "MasterOfShadowsHUD.h"
#include "Player/FirstPersonCharacter/FirstPersonCharacter.h"

AMasterOfShadowsGameMode::AMasterOfShadowsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Dynamic/Player/FirstPersonCharacter/Behavior/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AMasterOfShadowsHUD::StaticClass();
}
