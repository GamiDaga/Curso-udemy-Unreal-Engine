// Fill out your copyright notice in the Description page of Project Settings.

#include "Arrow.h"
#include "Characters/Enemys/EnemyMagian.h"


// Sets default values
AArrow::AArrow()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AArrow::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &AArrow::OnOverlap);
}

void AArrow::OnOverlap(AActor* me, AActor* other) {
	if (AEnemyMagian* enemy = Cast<AEnemyMagian>(other))
	{
		Cast<AEnemyMagian>(other)->ProcessDamageIn(damage);
	}
}

// Called every frame
void AArrow::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
