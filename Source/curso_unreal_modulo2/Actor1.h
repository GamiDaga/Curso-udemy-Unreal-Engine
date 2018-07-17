// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "CoreMinimal.h"
#include "F:/Program Files/Epic Games/UE_4.19/Engine/Source/Runtime/Core/Public/CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Actor1.generated.h"

UCLASS()
class CURSO_UNREAL_MODULO2_API AActor1 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActor1();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override; 		//sobre escribe el begin play de la superclase

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//velocidad de movimiento del actor
		UPROPERTY(EditAnywhere) FVector velocity;

		FTimerHandle timerHandleShoot; //identificador del timer 
		FTimerHandle timerHandleShootStop;
		FTimerHandle timerHandleRotate;
		FTimerHandle timerHandleRotateStop;
		FTimerHandle timerHandleMove;
		FTimerHandle timerHandleMoveStop;

	//variables de los timers
		UPROPERTY(EditAnywhere)	float timeShoot; 			//lapso de tiempo disparando
		UPROPERTY(EditAnywhere)	float timeRotate;			//lapso de tiempo rotando
		UPROPERTY(EditAnywhere)	float timeMove;				//lapso de tiempo moviendose
		UPROPERTY(EditAnywhere)	float timeBetweenShoot;		//lapso de tiempo entre disparo SpawnActor()
		UPROPERTY(EditAnywhere)	float timeBetweenMove;		//lapso de tiempo entre cada addActorLocalOffset()
		UPROPERTY(EditAnywhere)	float timeBetweenRotate;	//lapso de tiempo entre cada addActorLocalRotation()


		UPROPERTY(EditAnywhere)	FVector speedMove;			//direccion a la cual se mueve
		UPROPERTY(EditAnywhere)	FRotator speedRotate;		//direccion a la cual rota

	//metodos de los timers
		void Shoot();
		void ShootStop();
		void Rotate();
		void RotateStop();
		void Move();
		void MoveStop();

		UPROPERTY(EditAnywhere) TSubclassOf<class AActor> objetToSpawn; //targt de actor para spawnear

};
