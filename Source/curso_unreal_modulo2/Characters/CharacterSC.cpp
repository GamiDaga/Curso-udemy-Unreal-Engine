// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterSC.h"


// Sets default values
ACharacterSC::ACharacterSC()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACharacterSC::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACharacterSC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ACharacterSC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ACharacterSC::ProcessDamageIn(int damage)
{
	if (life > damage){
		life = life - damage;
	}else{
		life = 0;
	}
}

