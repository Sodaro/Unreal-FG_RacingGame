#pragma once
#include "Components/ActorComponent.h"
#include "RaceCarMovementComponent.generated.h"

class ARaceCar;

UCLASS(Meta = (BlueprintSpawnableComponent))
class URaceCarMovementComponent : public UActorComponent
{
	GENERATED_BODY()

	ARaceCar* Car;


	void HandleGround(float DeltaTime);
public:
	virtual void BeginPlay() override;
	URaceCarMovementComponent();
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AddForce(const FVector& Force);
	void AddImpulse(const FVector& Impulse);


	UPROPERTY(EditAnywhere)
	float AccelerationRate = 1000.f;

	UPROPERTY(EditAnywhere)
	float RollFriction = 0.8;

	UPROPERTY(EditAnywhere)
	float GripFriction = 4.0f;


	UPROPERTY(EditAnywhere)
	float TurnSpeed = 0.5f;

	FVector2D MoveInput;

	FVector Velocity;

	FQuat LastFallingRotationAmount;

	UPROPERTY(EditAnywhere)
	float FallRotationAmount = 20.f;

	bool IsGrounded = true;
};