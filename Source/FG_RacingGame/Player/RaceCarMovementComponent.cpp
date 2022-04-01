#include "RaceCarMovementComponent.h"
#include "RaceCar.h"
void URaceCarMovementComponent::HandleGround(float DeltaTime)
{
	UWorld* World = GetWorld();
	FVector FrontStartLocation = Car->GetActorLocation() + FVector{ 100,0,0 };
	FVector FrontEndLocation = FrontStartLocation + FVector{ 0,0,-200 };
	FVector BackStartLocation = Car->GetActorLocation() + FVector{ -100,0,0 };
	FVector BackEndLocation = BackStartLocation + FVector{ 0,0,-200 };
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
		Car->AddActorLocalRotation(LastFallingRotationAmount * DeltaTime);
	}

}
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

	//HandleGround(DeltaTime);
    FVector ForwardVec = Car->GetActorForwardVector();
    FVector Location = Car->GetActorLocation();

    // Apply acceleration
    Velocity += ForwardVec * AccelerationRate * MoveInput.Y * DeltaTime;

    // Apply friction (Acceleration friction)
    FVector RollingVelocity = Velocity.ProjectOnTo(ForwardVec);
    FVector GripVelocity = Velocity - RollingVelocity;

    RollingVelocity -= RollingVelocity * RollFriction * DeltaTime;
    GripVelocity -= GripVelocity * GripFriction * DeltaTime;

    Velocity = RollingVelocity + GripVelocity;

    // Apply movement
    float RemainingTime = DeltaTime;
    while (RemainingTime > 0.f)
    {
        FHitResult Hit;
        Car->AddActorWorldOffset(Velocity * RemainingTime, true, &Hit);

        // Hit something
        if (Hit.bBlockingHit)
        {
            // Depenetration
            if (Hit.bStartPenetrating)
            {
                Car->AddActorWorldOffset(Hit.Normal * (Hit.PenetrationDepth + 1.f));
            }
            // Otherwise, just redirect and keep going
            else
            {
                Velocity = FVector::VectorPlaneProject(Velocity, Hit.Normal);
                RemainingTime -= RemainingTime * Hit.Time;
            }
        }
        else
        {
            break;
        }
    }
    float Speed = Velocity.Size();
    Car->AddActorWorldRotation(FRotator(0.f, TurnSpeed * MoveInput.X * DeltaTime, 0.f));
}
