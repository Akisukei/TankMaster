// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
}

ATank* ATankPlayerController::GetControlledTank() const 
{
	ATank* ControlledTank = Cast<ATank>(GetPawn());

	if (ControlledTank) {
		UE_LOG(LogTemp, Error, TEXT("PlayerController possessing Tank: %s"), *ControlledTank->GetName());
	}
	else UE_LOG(LogTemp, Error, TEXT("Unable to possess a Tank"));

	return ControlledTank;
}