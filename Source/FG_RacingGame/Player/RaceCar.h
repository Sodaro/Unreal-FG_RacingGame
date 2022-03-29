#pragma once
#include "GameFramework/Pawn.h"
#include "RaceCar.generated.h"

class UBoxComponent;
class URaceCarMovementComponent;


UCLASS()
class ARaceCar : public APawn
{
	GENERATED_BODY()

public:
	ARaceCar();
	virtual void Tick(float DeltaTime) override;
	void SetupPlayerInputComponent(UInputComponent* InputComp) override;
	void HandleAccelerateInput(float Value);
	void HandleTurnInput(float Value);

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* BoxCollision;

	URaceCarMovementComponent* MoveComp;
	FVector2D MoveInput;

	FQuat LastFallingRotationAmount;

	UPROPERTY(EditAnywhere)
	float FallRotationAmount = 20.f;

	bool IsGrounded = true;
};