#pragma once

#include "GameFramework/GameMode.h"
#include "RaceGameMode.generated.h"

class UUserWidget;

UCLASS()
class ARaceGameMode : public AGameMode
{
	GENERATED_BODY()
public:
	ARaceGameMode();

	void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = Widgets)
	TSubclassOf<UUserWidget> OverlayWidgetClass;
};