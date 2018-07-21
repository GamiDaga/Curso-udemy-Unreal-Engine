// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Arrow.generated.h"

UCLASS()
class CURSO_UNREAL_MODULO2_API AArrow : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AArrow();
	UFUNCTION() void OnOverlap(AActor* me, AActor* other);
	UPROPERTY(EditAnywhere) int damage = 10;
	UPROPERTY(EditAnywhere) float speedBullet = 1000;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
