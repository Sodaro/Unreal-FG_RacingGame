#include "RaceOverlayWidget.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "RacePlayerStatusWidget.h"

void URaceOverlayWidget::NativeConstruct()
{
	Super::NativeConstruct();
	StatusWidgets.SetNum(4);
	//AddPlayerStatusWidget(0);

	UE_LOG(LogTemp, Log, TEXT("URaceOverlayWidget::NativeConstruct"));
}

void URaceOverlayWidget::AddPlayerStatusWidget(int PlayerIndex)
{
	static FName SlotNames[] =
	{
		TEXT("PlayerSlot0"),
		TEXT("PlayerSlot1"),
		TEXT("PlayerSlot2"),
		TEXT("PlayerSlot3"),
	};
	URacePlayerStatusWidget* PlayerStatus = NewObject<URacePlayerStatusWidget>(this, PlayerWidgetClass);
	StatusWidgets[PlayerIndex] = PlayerStatus;
	SetContentForSlot(SlotNames[PlayerIndex], PlayerStatus);
}
