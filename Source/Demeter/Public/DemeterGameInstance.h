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
	UPROPERTY(EditDefaultsOnly, Category = GlobalTweaks)
	float maximumTheoreticalRange; 
	UPROPERTY(EditDefaultsOnly, Category = GlobalTweaks)
	float maximumTheoreticalDrift;
	UPROPERTY(EditDefaultsOnly, Category = GlobalTweaks)
	float maximumTheoreticalSpread;
	UPROPERTY(EditDefaultsOnly, Category = GlobalTweaks)
	float maximumTheoreticalRecoil;
	UPROPERTY(EditDefaultsOnly, Category = GlobalTweaks)
	float maximumTheoreticalShotDelay;
	UPROPERTY(EditDefaultsOnly, Category = GlobalTweaks)
	float maximumTheoreticalReloadDelay;
};
