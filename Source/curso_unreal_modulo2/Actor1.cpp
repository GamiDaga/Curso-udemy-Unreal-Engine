// Fill out your copyright notice in the Description page of Project Settings.

#include "Actor1.h"


// Sets default values
AActor1::AActor1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AActor1::BeginPlay()
{
	Super::BeginPlay();
	
	Super::BeginPlay(); //esto es para cuando reemplazo el meto ejecutar lo que hay en la superclase
	//
	GetWorldTimerManager().SetTimer(timeHandleShoot, this, &AActor1::ShootStop, timeShoot);
	GetWorldTimerManager().SetTimer(timeHandleShootStop, this, &AActor1::Shoot, timeBetweenShoot, true);
	//timer de tiempo de vida del actor
	GetWorldTimerManager().SetTimer(timeHandleLive, this, &AActor1::Destroy, timeLive, false);
}

// Called every frame
void AActor1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalOffset(velocity);
	AddActorLocalRotation(rotSpeed);

}



//se ejecuta con un timer
void AActor1::Shoot()
{
	FVector  miPosision = GetActorLocation();
	FRotator miRotacion = GetActorRotation();
	GetWorld()->SpawnActor<AActor>(objetToSpawn, miPosision, miRotacion);
}

void AActor1::Move()
{
	AddActorLocalOffset(speedMove);
}

void AActor1::Rotate()
{
	AddActorLocalRotation(speedRotate);
}

void AActor1::ShootStop()
{
	GetWorldTimerManager().ClearTimer(timeHandleShoot);

	GetWorldTimerManager().SetTimer(timeHandleMoveStop, this, &AActor1::MoveStop, timeMove);
	GetWorldTimerManager().SetTimer(timeHandleMove, this, &AActor1::Move, timeBetweenMove, true);
}

void AActor1::MoveStop()
{
	GetWorldTimerManager().ClearTimer(timeHandleMove);

	GetWorldTimerManager().SetTimer(timeHandleRotateStop, this, &AActor1::RotateStop, timeRotate);
	GetWorldTimerManager().SetTimer(timeHandleRotate, this, &AActor1::Rotate, timeBetweenRotate, true);
}

void AActor1::RotateStop()
{
	GetWorldTimerManager().ClearTimer(timeHandleRotate);

	GetWorldTimerManager().SetTimer(timeHandleShootStop, this, &AActor1::ShootStop, timeShoot);
	GetWorldTimerManager().SetTimer(timeHandleShoot, this, &AActor1::Shoot, timeBetweenShoot, true);

}

void AActor1::Destroy()
{
	GetWorldTimerManager().ClearTimer(timeHandleLive);
	Destroy();
}
//timeHandleShoot
//timeHandleShootStop

//timeHandleRotate
//timeHandleRotateStop
//timeHandleMove
//timeHandleMoveStop
