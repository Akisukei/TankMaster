// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
///#include "Engine/World.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetControlledTank()) { 
		AimAtCrossHair(); 
	}
}

ATank* ATankPlayerController::GetControlledTank() const 
{
	ATank* ControlledPlayerTank = Cast<ATank>(GetPawn());

	if (!ControlledPlayerTank) {
		UE_LOG(LogTemp, Error, TEXT("PlayerController Unable to possess a Tank"));
	}

	return ControlledPlayerTank;
}

// Move tank barrel to aim at location with crosshair
void ATankPlayerController::AimAtCrossHair()
{
	FVector OutHitLocation = FVector(0);
	FString OutHitObject = "Nothing";

	if (GetCrosshairHitLocation(OutHitLocation, OutHitObject)) {
		
	}
	UE_LOG(LogTemp, Warning, TEXT("Targeting: %s, Hit Location: %s"), *OutHitObject, *OutHitLocation.ToString());
}

// Returns true if crosshair hits landscape AND returns OUT parameter of hit location
bool ATankPlayerController::GetCrosshairHitLocation(FVector& OutHitLocation, FString& OutHitObject) const
{
	/// find crosshair positions in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D CrosshairPosOnScreen = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	/// i.e viewportX * 0.5 is half, viewportY * 0.33 is one third from top; note they are uproperties

	/// use Unreal's built-in method to find hit object where crosshair is pointing at
	FHitResult HitResult;
	bool bHitObj = GetHitResultAtScreenPosition(
		CrosshairPosOnScreen, 
		ECollisionChannel::ECC_Visibility, 
		false, /// TraceComplex is collision complexity when line trace hits. False for basic, true for detailed
		HitResult
	);

	if(bHitObj) {
		OutHitLocation = HitResult.ImpactPoint;
		OutHitObject = HitResult.GetActor()->GetName();
	}

	return bHitObj;
}

/// Returns true if crosshair hits landscape AND returns OUT parameter of hit location
/*bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	/// find crosshair positions in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D CrosshairPosOnScreen = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	/// i.e viewportX * 0.5 is half, viewportY * 0.33 is one third from top

	/// 'De-project' from screen location with crosshair to world direction
	// GetLookDirection
	FVector CameraLocation;
	FVector CameraDirection;
	DeprojectScreenPositionToWorld(CrosshairPosOnScreen.X, CrosshairPosOnScreen.Y, CameraLocation, CameraDirection);
		
	/// line-trace from look direction and see what we hit (from max range)
	// GetLookVectorHitLocation
	FHitResult HitResult;
	FVector LineTraceEnd = CameraLocation + (CameraDirection * LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		CameraLocation,
		LineTraceEnd,
		ECollisionChannel::ECC_Visibility
	))
	{
		OutHitLocation = HitResult.Location;
		return true;
	}
	
	OutHitLocation = FVector(0);

	return false;
}*/