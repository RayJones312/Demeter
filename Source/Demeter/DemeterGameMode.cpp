// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "DemeterGameMode.h"
#include "DemeterHUD.h"
#include "DemeterCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADemeterGameMode::ADemeterGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ADemeterHUD::StaticClass();
}