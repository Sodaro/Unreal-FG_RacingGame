#include "RaceGameMode.h"
#include "Blueprint/UserWidget.h"
ARaceGameMode::ARaceGameMode()
{
	DefaultPawnClass = nullptr;

}

void ARaceGameMode::BeginPlay()
{
	Super::BeginPlay();

	auto* Overlay = NewObject<UUserWidget>(this, OverlayWidgetClass);
	Overlay->AddToViewport();
}
