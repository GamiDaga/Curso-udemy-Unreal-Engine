// Fill out your copyright notice in the Description page of Project Settings.

#include "Player1.h"
#include "Components/InputComponent.h"
#include "Engine/World.h"

// Sets default values
APlayer1::APlayer1()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APlayer1::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APlayer1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayer1::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("Vertical", this, &APlayer1::VerticalAxis);
	InputComponent->BindAxis("Horizontal", this, &APlayer1::HorizontalAxis);

}

void APlayer1::VerticalAxis(float value)
{
	float deltaTime = GetWorld()->GetDeltaSeconds();
	AddActorLocalOffset(FVector(value * speed * deltaTime, 0, 0), true);
}

void APlayer1::HorizontalAxis(float value)
{
	float deltaTime = GetWorld()->GetDeltaSeconds();
	AddActorLocalRotation(FRotator(0, value * horizontalAxysSensitivity * deltaTime, 0), true);
}

