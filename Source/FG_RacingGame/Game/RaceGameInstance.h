#pragma once

#include "Engine/GameInstance.h"
#include "RaceGameInstance.generated.h"

class ARaceCar;

UCLASS()
class URaceGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	void Init() override;

	UFUNCTION(BlueprintPure, Category = "Race|Game Instance", Meta = (DisplayName = "GetRaceGameInstance", WorldContext="WorldContext"))//context is parameter name
	static URaceGameInstance* Get(UObject* WorldContext);

	UPROPERTY(BlueprintReadOnly)
	TArray<ARaceCar*> Cars;
};