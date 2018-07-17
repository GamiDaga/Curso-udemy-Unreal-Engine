// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// #include "CoreMinimal.h"
#include "F:/Program Files/Epic Games/UE_4.19/Engine/Source/Runtime/Core/Public/CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Turret.generated.h"

UCLASS()
class CURSO_UNREAL_MODULO2_API ATurret : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATurret();

private:

	UPROPERTY(VisibleAnywhere) float realTime;

	FTimerHandle timerHandleTimer;
	FTimerHandle timerHandleRecharge;
	FTimerHandle timerHandleRateShoot; //identificador del timer 


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere) float maxLife = 100; 	//maximo de vida de la torreta
	UPROPERTY(VisibleAnywhere) float life = 100; 		//vida actual de la torreta

	UPROPERTY(EditAnywhere) float rechargeAmmo;  	//municioon disponible para recargar
	UPROPERTY(VisibleAnywhere) float maxAmmo = 10;	//maximo de municion el el cargador
	UPROPERTY(VisibleAnywhere) float ammo = 10;		//municion actual en el cargador
	UPROPERTY(EditAnywhere)	float timeBetweenShoot = 1;		//lapso de tiempo entre disparo SpawnActor()

	UPROPERTY(VisibleAnywhere) EComponentSocketType shootSocket;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere) TSubclassOf<class AActor> ammoActorToShoot;

	//variables de los timers
	UPROPERTY(EditAnywhere) float timeTimer = 1; //tiempo hasta la ejecucion del Timer
	UPROPERTY(EditAnywhere) float timeRecharge = 2; //tiempo hasta la ejecucion del Recharge
	


	void Timer();
	void Recharge();
	void Shoot();
	void Shooting();
	void ShootOrRecharge();
	void StopRate();

	
	
};
