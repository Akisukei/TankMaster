// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

void ATankAIController::BeginPlay() {

	Super::BeginPlay();

	ATank* ControlledAITank = GetPlayerTank();
}

ATank* ATankAIController::GetControlledTank() const
{
	ATank* ControlledAITank = Cast<ATank>(GetPawn());

	if (ControlledAITank) {
		UE_LOG(LogTemp, Warning, TEXT("AIController possessing Tank: %s"), *ControlledAITank->GetName());
	}
	else UE_LOG(LogTemp, Error, TEXT("AIController unable to possess a Tank"));

	return ControlledAITank;
}

ATank* ATankAIController::GetPlayerTank() const
{
	APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	ATank* PlayerTank = nullptr;

	if (PlayerPawn) {
		PlayerTank = Cast<ATank>(PlayerPawn);
	}
	else UE_LOG(LogTemp, Warning, TEXT("AIController cannot find player tank"));

	return PlayerTank;
}