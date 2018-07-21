// Fill out your copyright notice in the Description page of Project Settings.

#include "ArrowAlly.h"
#include "Characters/Enemys/EnemyMagian.h"

// Sets default values
AArrowAlly::AArrowAlly()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AArrowAlly::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &AArrowAlly::OnOverlap);
}

// Called every frame
void AArrowAlly::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorLocalOffset(FVector(velocity * DeltaTime, 0, 0), true);
}

void AArrowAlly::OnOverlap(AActor* me, AActor* other)
{
	if (AEnemyMagian* enemy = Cast<AEnemyMagian>(other))
	{
		Cast<AEnemyMagian>(other)->ProcessDamageIn(damage);
		Destroy();
	}
}