// Fill out your copyright notice in the Description page of Project Settings.

#include "Bullet.h"
#include "Characters/Enemys/EnemyMagian.h"
#include "Engine/Engine.h"


// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	
	OnActorBeginOverlap.AddDynamic(this, &ABullet::OnOverlap);
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorLocalOffset(FVector(speedBullet * DeltaTime, 0, 0) , true);

}

void ABullet::OnOverlap(AActor* me, AActor* other)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Magenta, TEXT("Overlap Detected"));
	if (AEnemyMagian* enemy = Cast<AEnemyMagian>(other))
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Magenta, TEXT("choque y soy EnemyMagian"));
		//other->ProcessDamageIn(damage);
		Cast<AEnemyMagian>(other)->ProcessDamageIn(damage);
		Destroy();
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Magenta, TEXT("choque y NO soy EnemyMagian"));

	}
}