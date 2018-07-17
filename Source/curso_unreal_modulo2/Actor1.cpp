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
	Super::BeginPlay(); //ejecuta el BeginPlay() de la superclase que se reemplasa con el override
	//inicia el tiempo de vida del Actor1
	GetWorldTimerManager().SetTimer(timerHandleLive, this, &AActor1::Destroy, timeLive);
	//inicia el loop de timers con Shoot
	GetWorldTimerManager().SetTimer(timerHandleShoot, this, &AActor1::Shoot, timeBetweenShoot, true); //inicia timer de shoot
	GetWorldTimerManager().SetTimer(timerHandleShootStop, this, &AActor1::ShootStop, timeShoot);	  //inicia timer para matar shoot

}

// Called every frame
void AActor1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}



//se ejecuta con un timer
void AActor1::Shoot()
{
	FVector  miPosision = GetActorLocation();	//toma locacion del actor
	FRotator miRotacion = GetActorRotation();	//toma rotacion del actor
	GetWorld()->SpawnActor<AActor>(objetToSpawn, miPosision, miRotacion); //spawnea con rotacion y locacion del Actor1
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
	GetWorldTimerManager().ClearTimer(timerHandleShoot);		//mata timer de shoot

	GetWorldTimerManager().SetTimer(timerHandleMoveStop, this, &AActor1::MoveStop, timeMove); //inicia timer para matar movimiento
	GetWorldTimerManager().SetTimer(timerHandleMove, this, &AActor1::Move, timeBetweenMove, true);  //inicia timer de movimiento
}

void AActor1::MoveStop()
{
	GetWorldTimerManager().ClearTimer(timerHandleMove); //mata timer de movimiento

	GetWorldTimerManager().SetTimer(timerHandleRotateStop, this, &AActor1::RotateStop, timeRotate);  //inicia timer para matar la rotacion
	GetWorldTimerManager().SetTimer(timerHandleRotate, this, &AActor1::Rotate, timeBetweenRotate, true);  //inicia timer de rotacion
}

void AActor1::RotateStop()
{
	GetWorldTimerManager().ClearTimer(timerHandleRotate);  //mata timer de rotacion

	GetWorldTimerManager().SetTimer(timerHandleShootStop, this, &AActor1::ShootStop, timeShoot);  //inicia timer para matar shoot
	GetWorldTimerManager().SetTimer(timerHandleShoot, this, &AActor1::Shoot, timeBetweenShoot, true);	//inicia timer de shoot

}

void AActor1::Destroy()
{
	Destroy();
	GetWorldTimerManager().ClearTimer(timerHandleLive);
}
