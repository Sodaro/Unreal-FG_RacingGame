#pragma once

#include "RacePowerup.h"
#include "RaceTurtleShellPowerup.generated.h"

class ARaceTurtleShell;

UCLASS(Abstract)
class URaceTurtleShellPowerup : public URacePowerup
{
	GENERATED_BODY()
public:
	void OnPowerupActivated_Implementation() override;

	UPROPERTY(EditDefaultsOnly, Category = Turtle)
	TSubclassOf<ARaceTurtleShell> TurtleClass;

	UPROPERTY(EditDefaultsOnly)
	float SpawnOffset = 200.f;
};