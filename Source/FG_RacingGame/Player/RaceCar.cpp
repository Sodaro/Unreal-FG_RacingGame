#include "RaceCar.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "RaceCarMovementComponent.h"
#include "FG_RacingGame/Powerup/RacePowerup.h"
ARaceCar::ARaceCar()
{
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	RootComponent = BoxCollision;
	MoveComp = CreateDefaultSubobject<URaceCarMovementComponent>(TEXT("MovementComponent"));
	PrimaryActorTick.bCanEverTick = true;
}

void ARaceCar::BeginPlay()
{
	Super::BeginPlay();
}


void ARaceCar::Tick(float DeltaSeconds)
{
	//Super::Tick(DeltaSeconds);
	if (Powerup != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 0.f, FColor::Emerald, Powerup->GetClass()->GetName(), true, FVector2D(4.f));
	}
}

void ARaceCar::SetupPlayerInputComponent(UInputComponent* InputComp)
{
	InputComp->BindAxis(TEXT("Accelerate"), this, &ARaceCar::HandleAccelerateInput);
	InputComp->BindAxis(TEXT("Turn"), this, &ARaceCar::HandleTurnInput);
	InputComp->BindAction(TEXT("Powerup"), IE_Pressed, this, &ARaceCar::HandleActivatePowerup);
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
	MoveComp->MoveInput.Y = Value;

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
	MoveComp->MoveInput.X = Value;
}

void ARaceCar::HandleActivatePowerup()
{
	if (Powerup != nullptr)
		Powerup->OnPowerupActivated();
}


