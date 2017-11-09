// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "DemeterGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class DEMETER_API UDemeterGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	//tuning value for the upper limits of weapon stats.
	float maximumTheoreticalRange; 
	float maximumTheoreticalDrift;
	float maximumTheoreticalSpread;
	float maximumTheoreticalRecoil;
	float maximumTheoreticalShotDelay;
	float maximumTheoreticalReloadDelay;
};
