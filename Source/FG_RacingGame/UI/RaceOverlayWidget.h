#pragma once
#include "Blueprint/UserWidget.h"
#include "RaceOverlayWidget.generated.h"

UCLASS()
class URaceOverlayWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	void NativeConstruct() override;
	void AddPlayerStatusWidget(int PlayerIndex);

	UPROPERTY(EditAnywhere, Category = RaceOverlay)
	TSubclassOf<UUserWidget> PlayerWidgetClass;
};