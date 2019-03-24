// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BP_Functions.generated.h"

/**
 * 
 */
UCLASS()
class PROCEDURAL_API UBP_Functions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

		UFUNCTION(BlueprintCallable, Category="Justin")
		static UTexture2D* NewTexture2D(int32 inSizeX, int32 inSizeY, EPixelFormat InFormat = PF_B8G8R8A8);
};
