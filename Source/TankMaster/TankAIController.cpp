// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

void ATankAIController::BeginPlay() 
{

	Super::BeginPlay();

	FVector ControlledAITank = GetPlayerTankLocation(); // TODO make sure it doesnt need to be ATank*
}

void ATankAIController::Tick(float DeltaTime) 
{
	Super::Tick(DeltaTime);

	GetControlledTank()->AimAt(GetPlayerTankLocation());
}

ATank* ATankAIController::GetControlledTank() const
{
	ATank* ControlledAITank = Cast<ATank>(GetPawn());

	if (!ControlledAITank) {
		UE_LOG(LogTemp, Error, TEXT("AIController unable to possess a Tank"));
	}

	return ControlledAITank;
}

FVector ATankAIController::GetPlayerTankLocation() const
{
	APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	ATank* PlayerTank = nullptr;

	if (PlayerPawn) {
		PlayerTank = Cast<ATank>(PlayerPawn);
	}
	else UE_LOG(LogTemp, Warning, TEXT("AIController cannot find player tank"));

	return PlayerTank->GetActorLocation();
}