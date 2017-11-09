// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ModularGun.generated.h"

UCLASS()
class DEMETER_API AModularGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AModularGun();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GunStat)
	float fireRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GunStat)
	float reloadSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GunStat)
	float recoilControl;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GunStat)
	float accuracy;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GunStat)
	float range;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GunStat)
	float stability;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GunStat)
	float damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GunStat)
	float projectileVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GunStat)
	int magazineSize; //how many rounds fit in magazine

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GunStat)
	int currentMag; //number of rounds in current mag

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GunStat)
	int reserveAmmo; //how much ammo is left

protected:
	bool canFire; //whether or not the gun is able to shoot on this frame
	bool isReloading;
	float magDelay; //how long it takes to reload the mag, calculated using reloadSpeed;
	float shotInterval; //Time between shots calculated using fireRate'
	float driftSqrMagnitude; //the actual sqrmag of the vector to determine drift
	float spread; //the actual sqrmag of the vector to determine innacuracy

	//These will probably get moved to the projectile class
	float shotDamage; //actual, not theoretical, damage delivered to enemies determined by range falloff 
	float projectileDistanceTraveled; //faked by using time elapsed instead of actually calculating distance

	FTimerHandle ReloadTimer;
	FTimerHandle ShotTimer;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Refresh weapon and determine weapon stats based on equipped parts
	virtual void UpdateWeaponStats();
	// Fire a single bullet. 
	virtual void FireWeapon();
	// Reloads the magazine
	virtual void ReloadWeapon();
	// Stows the weapon so we don't fire with when giving the input to fire
	virtual void Stow();
	// Equips the weapon so we can fire with it
	virtual void Equip();
};
