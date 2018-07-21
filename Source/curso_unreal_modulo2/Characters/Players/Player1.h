// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Player1.generated.h"


UCLASS()
class CURSO_UNREAL_MODULO2_API APlayer1 : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayer1();

private:

	UPROPERTY(VisibleAnywhere) float realTime;

	FTimerHandle timerHandleTimer;
	FTimerHandle timerHandleRecharge;
	FTimerHandle timerHandleFire; //identificador del timer

	UPROPERTY(EditAnywhere) float speed = 300;
	UPROPERTY(EditAnywhere) float horizontalAxysSensitivity = 400;
	UPROPERTY(EditAnywhere) float life = 100;
	UPROPERTY(VisibleAnywhere) float maxLife = 100; 	//maximo de vida de la torreta

	bool forwardPressed = false;

	bool fire = true;
	bool reload = false;


	UPROPERTY(EditAnywhere) float rechargeAmmo;  	//municioon disponible para recargar
	UPROPERTY(VisibleAnywhere) float maxAmmo = 10;	//maximo de municion el el cargador
	UPROPERTY(VisibleAnywhere) float ammo = 10;		//municion actual en el cargador
	UPROPERTY(EditAnywhere)	float rateFire = 0.3;		//lapso de tiempo entre disparo SpawnActor()

	UPROPERTY(EditAnywhere) TSubclassOf<class AActor> ammoActorToShoot;

	//variables de los timers
	UPROPERTY(EditAnywhere) float timeTimer = 1; //tiempo hasta la ejecucion del Timer
	UPROPERTY(EditAnywhere) float timeRecharge = 2; //tiempo hasta la ejecucion del Recharge

protected:
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	void VerticalAxis(float value);
	void HorizontalAxis(float value);

	void ForwardPressed();
	void ForwardReleased();

	void ShootOrRecharge();
	void Recharge();
	void Shooting();
	void Shoot();
	void StopShoot();

	void ProcessDamageIn(int damage);
};
