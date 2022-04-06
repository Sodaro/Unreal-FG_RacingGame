#pragma once

#include "RacePowerup.h"
#include "RaceBoostPowerup.generated.h"

class URaceCarMovementComponent;
UCLASS()
class URaceBoostPowerup : public URacePowerup
{
	GENERATED_BODY()
public:
	void OnPowerupActivated_Implementation() override;
	void Setup_Implementation() override;
	void TickActive_Implementation(float DeltaTime) override;

	bool ShouldDeactivate_Implementation() override;

private:
	UPROPERTY()
	URaceCarMovementComponent* MoveComp;

	float BoostTime;
};