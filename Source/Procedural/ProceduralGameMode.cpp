// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "ProceduralGameMode.h"
#include "ProceduralHUD.h"
#include "ProceduralCharacter.h"
#include "UObject/ConstructorHelpers.h"

AProceduralGameMode::AProceduralGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AProceduralHUD::StaticClass();
}


