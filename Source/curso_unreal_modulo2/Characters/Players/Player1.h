// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Player1.generated.h"

UCLASS()
class CURSO_UNREAL_MODULO2_API APlayer1 : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayer1();

private:
	UPROPERTY(EditAnywhere) float speed = 300;
	UPROPERTY(EditAnywhere) float horizontalAxysSensitivity = 400;
	UPROPERTY(VisibleAnywhere) float life = 400;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void VerticalAxis(float value);

	void HorizontalAxis(float value);
	

};
