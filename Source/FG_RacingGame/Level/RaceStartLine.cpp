#include "RaceStartLine.h"
#include "FG_RacingGame/Player/RaceCar.h"
#include "Kismet/GameplayStatics.h"
#include "../Game/RaceGameInstance.h"
#include "../Game/RaceGameMode.h"
#include "../UI/RaceOverlayWidget.h"
#include "../UI/RacePlayerStatusWidget.h"

ARaceStartLine::ARaceStartLine()
{
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;
}

void ARaceStartLine::BeginPlay()
{
	Super::BeginPlay();

	AGameModeBase* GameMode = GetWorld()->GetAuthGameMode();

	FTransform SpawnTransform = GetActorTransform();

	for (int i = 0; i < NumberOfPlayers; i++)
	{
		APlayerController* PlayerController = UGameplayStatics::GetPlayerControllerFromID(this,i);
		if (PlayerController == nullptr)
			PlayerController = UGameplayStatics::CreatePlayer(this, i);

		PlayerController->bAutoManageActiveCameraTarget = false;		
		auto Car = GetWorld()->SpawnActor<ARaceCar>(CarClass, SpawnTransform);
		Car->PlayerIndex = i;
		PlayerController->Possess(Car);

		URaceGameInstance* GameInstance = URaceGameInstance::Get(this);
		GameInstance->Cars.Add(Car);

		ARaceGameMode* CoolGameMode = ARaceGameMode::Get(this);
		CoolGameMode->OverlayWidget->AddPlayerStatusWidget(i);
		CoolGameMode->OverlayWidget->StatusWidgets[i]->SetPlayerName(FString::Printf(TEXT("Player %d"), i + 1));

		SpawnTransform.AddToTranslation(GetActorRightVector() * 200.f);
	}
	
}