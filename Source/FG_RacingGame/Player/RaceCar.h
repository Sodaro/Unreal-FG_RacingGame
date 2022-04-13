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
	void BeginPlay() override;
	void EndPlay(const EEndPlayReason::Type Reason) override;
	virtual void Tick(float DeltaTime) override;
	void SetupPlayerInputComponent(UInputComponent* InputComp) override;
	void HandleAccelerateInput(float Value);
	void HandleTurnInput(float Value);
	void HandleActivatePowerup();
	void EquipPowerup(URacePowerup* InPowerup);

	bool HasEquippedPowerup() { return Powerup != nullptr; }
	
	int32 PlayerIndex = 0;

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* BoxCollision;

	UPROPERTY(VisibleAnywhere)
	URaceCarMovementComponent* MoveComp;

	UPROPERTY(EditAnywhere)
	TSubclassOf<URacePowerup> PowerupClass;

	UPROPERTY() //or TWeakObjectPtr
	URacePowerup* Powerup;
	bool bPowerupActivated = false;
};