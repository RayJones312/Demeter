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
	
}

// Called every frame
void AModularGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AModularGun::UpdateWeaponStats()
{
	UDemeterGameInstance* gi = Cast<UDemeterGameInstance>(GetGameInstance());
	shotInterval = (gi->maximumTheoreticalShotDelay) / fireRate;
	driftSqrMagnitude = (gi->maximumTheoreticalDrift) / stability;
	magDelay = (gi->maximumTheoreticalReloadDelay) / reloadSpeed;
	spread = (gi->maximumTheoreticalSpread) / accuracy;
}

void AModularGun::FireWeapon()
{
}

void AModularGun::ReloadWeapon()
{
	
	currentMag = 0;

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

