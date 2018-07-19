// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyMagian.h"
#include "Engine/Engine.h"


// Sets default values
AEnemyMagian::AEnemyMagian()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyMagian::BeginPlay()
{
	Super::BeginPlay();
	life = initialLife;
	
}

// Called every frame
void AEnemyMagian::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (life <= 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("I WILL RETURN!!!!"));
		Destroy();

	}
}

// Called to bind functionality to input
void AEnemyMagian::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemyMagian::ProcessDamageIn(int damage)
{
	if (life > damage)
	{
		life = life - damage;
	}
	else
	{
		life = 0;
	}
}

