// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Tank.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TANKMASTER_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:

	/* VARIABLES */

	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.33f;

	UPROPERTY(EditAnywhere)
	int LineTraceRange = 1000000;

	/* METHODS */

	ATank* GetControlledTank() const;

	// Move tank barrel to aim at location with crosshair
	void AimAtCrossHair();

	// Returns true if crosshair hits landscape AND returns OUT parameter of hit location
	bool GetCrosshairHitLocation(FVector& OutHitLocation, FString& OutHitObject) const;

	/// Returns true if crosshair hits landscape AND returns OUT parameter of hit location
	///bool GetSightRayHitLocation(FVector& OutHitLocation) const;
};
