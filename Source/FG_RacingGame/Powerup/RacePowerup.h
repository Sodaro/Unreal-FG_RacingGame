#pragma once
#include "CoreMinimal.h"
#include "RacePowerup.generated.h"
UCLASS(Blueprintable)
class URacePowerup : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnPowerupActivated();
};