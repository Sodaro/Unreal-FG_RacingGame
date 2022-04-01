#pragma once
#include "GameFramework/Pawn.h"
#include "RaceCar.generated.h"

class UBoxComponent;
class URaceCarMovementComponent;
class URacePowerup;

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
	void HandleActivatePowerup();
	void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* BoxCollision;

	UPROPERTY(VisibleAnywhere)
	URaceCarMovementComponent* MoveComp;

	UPROPERTY(EditAnywhere)
	TSubclassOf<URacePowerup> PowerupClass;

	UPROPERTY() //or TWeakObjectPtr
	URacePowerup* Powerup;
};