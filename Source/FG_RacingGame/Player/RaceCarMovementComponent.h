#pragma once
#include "Components/ActorComponent.h"
#include "RaceCarMovementComponent.generated.h"

class ARaceCar;

UCLASS(Meta = (BlueprintSpawnableComponent))
class URaceCarMovementComponent : public UActorComponent
{
	GENERATED_BODY()

	ARaceCar* Car;

public:
	virtual void BeginPlay() override;
	URaceCarMovementComponent();
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	float CurrentSpeed = 0.f;

	UPROPERTY(EditAnywhere)
	float MaxSpeed = 500.f;

	UPROPERTY(EditAnywhere)
	float AccelerationRate = 100.f;

	UPROPERTY(EditAnywhere)
	float BrakeFactor = 0.75f;

	FVector Velocity;
};