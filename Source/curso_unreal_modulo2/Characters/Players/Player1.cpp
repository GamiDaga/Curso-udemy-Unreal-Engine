// Fill out your copyright notice in the Description page of Project Settings.

#include "Player1.h"
#include "CoreMinimal.h"
#include "Components/InputComponent.h"
#include "Engine/Engine.h"
#include "Engine/World.h"  
#include "TimerManager.h"


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


// Called to bind functionality to input
void APlayer1::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("Vertical", this, &APlayer1::VerticalAxis);
	InputComponent->BindAxis("Horizontal", this, &APlayer1::HorizontalAxis);

	InputComponent->BindAction("Fire", IE_Pressed, this, &APlayer1::ForwardPressed);
	InputComponent->BindAction("Fire", IE_Released, this, &APlayer1::ForwardReleased);
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



void APlayer1::ForwardPressed()
{
	forwardPressed = true;
	GetWorldTimerManager().SetTimer(timerHandleFire, this, &APlayer1::ShootOrRecharge, rateFire, true, 0);
}

void APlayer1::ForwardReleased()
{
	forwardPressed = false;
	StopShoot();
}


void APlayer1::ShootOrRecharge()
{
	UE_LOG(LogTemp, Warning, TEXT("entra a ShootOrRecharge"));

	if (fire)
	{
		if (!reload) {
			if (ammo > 0) {
				Shoot();
			}
			else 
			{
				UE_LOG(LogTemp, Warning, TEXT("entra a rechargeAmmo"));

				fire = false;
				reload = true;
				GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, TEXT("Player: RELOAD!"));
				GetWorldTimerManager().SetTimer(timerHandleRecharge, this, &APlayer1::Recharge, timeRecharge);
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("recargando"));
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, TEXT("Player: Wait man, I'm reloading bullets!"));
		}
	}
	else if (rechargeAmmo > 0 || ammo > 0)
	{
		fire = true;
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("NO AMMO"));
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, TEXT("Player1: NO AMMO!!"));
	}
}

void APlayer1::Recharge()
{
	UE_LOG(LogTemp, Warning, TEXT("entra a Recharge"));

	if (rechargeAmmo >= maxAmmo) {
		UE_LOG(LogTemp, Warning, TEXT("asd"));
		ammo = maxAmmo;
		rechargeAmmo = rechargeAmmo - maxAmmo;
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, TEXT("Player1: The recharge have finished, COME ON bitches!!"));
	}
	else if (rechargeAmmo <= 0) {
		GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Blue, TEXT("Player1: NO AMMO!!"));
		fire = false;
	}
	else {
		ammo = rechargeAmmo;
		rechargeAmmo = 0;
	}
	fire = true;
	reload = false;

	GetWorldTimerManager().ClearTimer(timerHandleRecharge);

}

void APlayer1::Shoot()
{
	UE_LOG(LogTemp, Warning, TEXT("entra a Shoot"));

	ammo--;
	GetWorld()->SpawnActor<AActor>(ammoActorToShoot, GetActorLocation(), GetActorRotation());

}

void APlayer1::StopShoot()
{
	GetWorldTimerManager().ClearTimer(timerHandleFire);
}






void APlayer1::ProcessDamageIn(int damage)
{
	if (life > damage)
	{
		life = life - damage;
	}
	else
	{
		life = 0;
	}
	//GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Green, TEXT(FString.FromInt(life));

}

// Called every frame
void APlayer1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	realTime = realTime + DeltaTime;

	if (life <= 0)
	{
		Destroy();
	}

}
