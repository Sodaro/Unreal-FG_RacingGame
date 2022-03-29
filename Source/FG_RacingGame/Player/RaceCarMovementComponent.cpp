#include "RaceCarMovementComponent.h"
#include "RaceCar.h"
void URaceCarMovementComponent::BeginPlay()
{
	Super::BeginPlay();
	Car = Cast<ARaceCar>(GetOwner());
}
URaceCarMovementComponent::URaceCarMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}
void URaceCarMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	FVector2D Input = Car->MoveInput;

	if (Input.Y != 0 && Car->IsGrounded)
	{
		if (Input.Y < 0)
		{
			CurrentSpeed -= CurrentSpeed * BrakeFactor * DeltaTime;
		}
		else
		{
			CurrentSpeed += AccelerationRate * DeltaTime;
		}
		Velocity = Car->GetActorForwardVector() * CurrentSpeed;
	}

	if (!Car->IsGrounded)
	{
		Velocity += FVector{ 0,0,-10 }*DeltaTime;
	}
	Car->AddActorWorldOffset(Velocity * DeltaTime);
}
