// Fill out your copyright notice in the Description page of Project Settings.

#include "ModularGun.h"
#include "DemeterGameInstance.h"

// Sets default values
AModularGun::AModularGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void AModularGun::BeginPlay()
{
	Super::BeginPlay();
	UpdateWeaponStats();
	RefillMag();
	canFire = true;

}

// Called every frame
void AModularGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AModularGun::UpdateWeaponStats()
{
	UDemeterGameInstance* gi = Cast<UDemeterGameInstance>(GetGameInstance());
	
	//parse bonuses and penalties from weaponparts

	//calculate true values from the designer-friendly ones
	shotInterval = (gi->maximumTheoreticalShotDelay) / fireRate;
	driftSqrMagnitude = (gi->maximumTheoreticalDrift) / stability;
	magDelay = (gi->maximumTheoreticalReloadDelay) / reloadSpeed;
	spread = (gi->maximumTheoreticalSpread) / accuracy;
}

void AModularGun::HandleFireInput()
{
	if (canFire && currentMag > 0)
	{
		if (!automatic)
		{
			FireWeapon();
			canFire = false;
			GetWorldTimerManager().SetTimer(ShotTimer, this, &AModularGun::ResetFire, shotInterval, false);
		}
		else
		{
			FireWeapon();
			canFire = true;
			GetWorldTimerManager().SetTimer(ShotTimer, this, &AModularGun::FireWeapon, shotInterval, true);
		}
		if (firesEachPull)
		{
			FireWeapon();
		}
	}
}

void AModularGun::ReleaseFireInput()
{
	if (automatic)
	{
		GetWorldTimerManager().ClearTimer(ShotTimer);
	}
}

void AModularGun::ResetFire()
{
	canFire = true;
}

void AModularGun::FireWeapon()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("FIRE!"));
}

void AModularGun::ReloadWeapon()
{
	currentMag = 0;
	GetWorldTimerManager().SetTimer(ShotTimer, this, &AModularGun::RefillMag, magDelay, false);	
}

void AModularGun::RefillMag()
{
	currentMag = magazineSize;
	reserveAmmo -= magazineSize;
}

void AModularGun::Stow()
{
	canFire = false;
}

void AModularGun::Equip()
{
	canFire = true;
}

