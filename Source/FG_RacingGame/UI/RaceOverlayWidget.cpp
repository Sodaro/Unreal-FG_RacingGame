#include "RaceOverlayWidget.h"

void URaceOverlayWidget::NativeConstruct()
{
	Super::NativeConstruct();
	AddPlayerStatusWidget(0);

	UE_LOG(LogTemp, Log, TEXT("URaceOverlayWidget::NativeConstruct"));
}

void URaceOverlayWidget::AddPlayerStatusWidget(int PlayerIndex)
{
	UUserWidget* PlayerStatus = NewObject<UUserWidget>(this, PlayerWidgetClass);
}
