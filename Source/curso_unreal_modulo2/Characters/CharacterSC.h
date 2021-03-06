// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CharacterSC.generated.h"

UCLASS()
class CURSO_UNREAL_MODULO2_API ACharacterSC : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACharacterSC();

private:
	int life;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void ProcessDamageIn(int damage);


	void setLife(int newLife);

	int getLife();
	
};
