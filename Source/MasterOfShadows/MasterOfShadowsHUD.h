// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once 
#include "GameFramework/HUD.h"
#include "MasterOfShadowsHUD.generated.h"

UCLASS()
class AMasterOfShadowsHUD : public AHUD
{
	GENERATED_BODY()

public:
	AMasterOfShadowsHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

