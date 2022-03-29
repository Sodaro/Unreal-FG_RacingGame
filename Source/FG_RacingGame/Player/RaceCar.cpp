#include "RaceCar.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "RaceCarMovementComponent.h"
ARaceCar::ARaceCar()
{
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	RootComponent = BoxCollision;
	MoveComp = CreateDefaultSubobject<URaceCarMovementComponent>(TEXT("MovementComponent"));
}

void ARaceCar::Tick(float DeltaTime)
{
	UWorld* World = GetWorld();
	FVector FrontStartLocation = GetActorLocation() + FVector{ 100,0,0 };
	FVector FrontEndLocation = FrontStartLocation + FVector{ 0,0,-200 };
	FVector BackStartLocation = GetActorLocation() + FVector{ -100,0,0 };
	FVector BackEndLocation = BackStartLocation + FVector{0,0,-200};
	FHitResult FrontHit, BackHit;
	World->LineTraceSingleByChannel(FrontHit, FrontStartLocation, FrontEndLocation, ECollisionChannel::ECC_WorldStatic);
	World->LineTraceSingleByChannel(BackHit, BackStartLocation, BackEndLocation, ECollisionChannel::ECC_WorldStatic);
	
	IsGrounded = FrontHit.bBlockingHit || BackHit.bBlockingHit;

	if (BackHit.bBlockingHit && !FrontHit.bBlockingHit)
	{
		LastFallingRotationAmount = FQuat::MakeFromEuler({ 0,FallRotationAmount,0 });
	}
	else if (!BackHit.bBlockingHit && FrontHit.bBlockingHit)
	{
		LastFallingRotationAmount = FQuat::MakeFromEuler({ 0,-FallRotationAmount,0 });
	}

	if (!LastFallingRotationAmount.IsIdentity())
	{
		AddActorLocalRotation(LastFallingRotationAmount * DeltaTime);
	}
}

void ARaceCar::SetupPlayerInputComponent(UInputComponent* InputComp)
{
	InputComp->BindAxis(TEXT("Accelerate"), this, &ARaceCar::HandleAccelerateInput);
	InputComp->BindAxis(TEXT("Turn"), this, &ARaceCar::HandleTurnInput);
}
void ARaceCar::HandleAccelerateInput(float Value)
{
	Value = UKismetMathLibrary::FClamp(Value, -1.f, 1.f);
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			INDEX_NONE,
			0.f,
			FColor::Magenta,
			FString::Printf(TEXT("Accelerate: %f"), Value));
	}
	MoveInput.Y = Value;

}
void ARaceCar::HandleTurnInput(float Value)
{
	Value = UKismetMathLibrary::FClamp(Value, -1.f, 1.f);
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
		INDEX_NONE,
			0.f,
			FColor::Magenta,
			FString::Printf(TEXT("Turn: %f"), Value));
	}
	MoveInput.X = Value;
}