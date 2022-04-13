#pragma once

#include "GameFramework/GameMode.h"
#include "RaceGameMode.generated.h"

class URaceOverlayWidget;

UCLASS()
class ARaceGameMode : public AGameMode
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintPure, Category = "Race|GameMode", Meta = (DisplayName = "GetRaceGameMode", WorldContext = "WorldContext"))//context is parameter name
	static ARaceGameMode* Get(UObject* WorldContext);
	
	ARaceGameMode();

	void StartMatch() override;

	UPROPERTY(EditDefaultsOnly, Category = Widgets)
	TSubclassOf<URaceOverlayWidget> OverlayWidgetClass;

	UPROPERTY()
	URaceOverlayWidget* OverlayWidget;
};