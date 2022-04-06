#pragma once
#include "CoreMinimal.h"
#include "RacePowerup.generated.h"
UCLASS(Blueprintable)
class URacePowerup : public UObject
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintNativeEvent)
	void Setup();

	UFUNCTION(BlueprintNativeEvent)
	void OnPowerupActivated();

	UFUNCTION(BlueprintNativeEvent)
	void TickActive(float DeltaTime);

	UFUNCTION(BlueprintNativeEvent)
	bool ShouldDeactivate();


	UFUNCTION(BlueprintCallable)
	AActor* GetOwner() { return Cast<AActor>(GetOuter()); }

};