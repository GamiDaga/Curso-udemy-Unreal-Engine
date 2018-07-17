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
	virtual void BeginPlay() override; 		//sobre escribe el beguin play de la puperclase

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//velocidad de movimiento del actor
		UPROPERTY(EditAnywhere) FVector velocity;

		FTimerHandle timeHandleShoot; //identificador del timer 
		FTimerHandle timeHandleShootStop;
		FTimerHandle timeHandleRotate;
		FTimerHandle timeHandleRotateStop;
		FTimerHandle timeHandleMove;
		FTimerHandle timeHandleMoveStop;
		FTimerHandle timeHandleLive;


		UPROPERTY(EditAnywhere)	float timeShoot;
		UPROPERTY(EditAnywhere)	float timeRotate;
		UPROPERTY(EditAnywhere)	float timeMove;
		UPROPERTY(EditAnywhere)	float timeBetweenShoot;
		UPROPERTY(EditAnywhere)	float timeBetweenMove;
		UPROPERTY(EditAnywhere)	float timeBetweenRotate;

		UPROPERTY(EditAnywhere)	float timeLive;

		UPROPERTY(EditAnywhere)	FVector speedMove;
		UPROPERTY(EditAnywhere)	FRotator speedRotate;

		void Destroy();

		void Shoot();
		void ShootStop();
		void Rotate();
		void RotateStop();
		void Move();
		void MoveStop();

		//deja para setear un actor para spawnear
		UPROPERTY(EditAnywhere)
		TSubclassOf<class AActor> objetToSpawn;

		UPROPERTY(EditAnywhere)
		FRotator rotSpeed;

		AActor1();
	
};
