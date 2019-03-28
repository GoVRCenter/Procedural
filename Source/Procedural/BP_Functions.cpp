// Fill out your copyright notice in the Description page of Project Settings.

#include "BP_Functions.h"
#include "Engine/Texture2D.h"
#include "Math.h"
#include <complex>


//void UBP_Functions::TextureGenerator(int32 inSizeX, int32 inSizeY)
UTexture2D*  UBP_Functions::NewTexture2D(int32 inSizeX, int32 inSizeY, EPixelFormat inFormat)
{
	UTexture2D* t = UTexture2D::CreateTransient(inSizeX, inSizeY, inFormat);
	FTexture2DMipMap& Mip =  t->PlatformData->Mips[0];
	void* Data = Mip.BulkData.Lock(LOCK_READ_WRITE);
	int32 stride = (int32)(sizeof(uint8) * 4);

	//Image generation done here pixel by pixel:
	//int32 maxCount = 30;
	//int64 minR, maxR, minI, maxI;

	TArray<FColor> colors;
	//int64 pixelStream = t->PlatformData->SizeX * t->PlatformData->SizeY;
	for (int64 i = 0; i < t->PlatformData->SizeX; i++) {
		for (int64 j = 0; j < t->PlatformData->SizeY; j++) {
			if (i % 4 && j % 4){ colors.Add(FColor::Emerald); }
			else { colors.Add(FColor::White); }
		}
	}


	// End image generation

	//Now copy the generated image to the newly created texture file.
	//UE_LOG(LogTemp, Warning, TEXT("%d"), t->PlatformData->SizeX * t->PlatformData->SizeY * stride);
	FMemory::Memcpy(Data, colors.GetData(), t->PlatformData->SizeX * t->PlatformData->SizeY * stride);
	Mip.BulkData.Unlock();
	t->UpdateResource();

	return t;
}
