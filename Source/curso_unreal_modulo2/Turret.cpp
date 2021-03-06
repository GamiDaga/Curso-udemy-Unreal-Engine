// Fill out your copyright notice in the Description page of Project Settings.

#include "Turret.h"
#include "Engine/Engine.h"
#include "Engine/World.h"  //esto lo acabo de inclior recien solo por que me acorde, siempre andubo el proyecto sin incluirlo (acunque despues de incluirlo intente denuevo y no andubo igual)
#include "TimerManager.h"



// Sets default values
ATurret::ATurret()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATurret::BeginPlay()
{
	Super::BeginPlay();
	
	// GetWorldTimerManager().SetTimer(timerHandleTimer, this, &ATurret:Timer, timer, true);
	// comp = GetComponentByName(FName PointShoot);
}


void ATurret::Shoot()
{
	ammo--;
	// shootSocket = GetMesh()->GetSocketByName(FName("PointShoot"));
	GetWorld()->SpawnActor<AActor>(ammoActorToShoot,GetActorLocation(),GetActorRotation()); 

}

void ATurret::Recharge()
{

		if(rechargeAmmo >= maxAmmo){
			ammo = maxAmmo;
			rechargeAmmo = rechargeAmmo - maxAmmo;
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("Turret: RECHARGED!!!"));
		}else if(rechargeAmmo <= 0){
			GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Yellow, TEXT("Turret: NO AMMO 1!!"));
		}else{
			ammo = rechargeAmmo;
			rechargeAmmo = 0;
		}
	GetWorldTimerManager().ClearTimer(timerHandleRecharge);
}

void ATurret::StopRate()
{
	GetWorldTimerManager().ClearTimer(timerHandleRateShoot);
}

void ATurret::Shooting()
{
	if (!timerHandleRateShoot.IsValid()) {
		GEngine->AddOnScreenDebugMessage(-1, 0.015f, FColor::Yellow, TEXT("Turret: Shooting!" ));

		Shoot();
		GetWorldTimerManager().SetTimer(timerHandleRateShoot, this, &ATurret::StopRate, timeBetweenShoot);
	}
}

void ATurret::ShootOrRecharge()
{
	
	if (ammo > 0) {
		Shooting();
	}else if(rechargeAmmo > 0 ){
		// GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("debug!"));
		//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, TEXT("RECHARGING!!!"));
		GetWorldTimerManager().SetTimer(timerHandleRecharge, this, &ATurret::Recharge, timeRecharge);
	}else if(ammo ==0 && rechargeAmmo == 0){
		GEngine->AddOnScreenDebugMessage(-1, 0.01f, FColor::Yellow, TEXT("Turret: NO AMMO 2!!"));
	}
}
 

// Called every frame
void ATurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	realTime = realTime + DeltaTime;
	
	if (!timerHandleRecharge.IsValid()) {
		ShootOrRecharge();
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 0.01f, FColor::Yellow, TEXT("Turret: Reload!"));
	}

}