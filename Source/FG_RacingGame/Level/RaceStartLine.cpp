#include "RaceStartLine.h"
#include "FG_RacingGame/Player/RaceCar.h"
#include "Kismet/GameplayStatics.h"

#include "../Game/RaceGameInstance.h"

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
		PlayerController->Possess(Car);

		URaceGameInstance* GameInstance = URaceGameInstance::Get(this);
		GameInstance->Cars.Add(Car);

		SpawnTransform.AddToTranslation(GetActorRightVector() * 200.f);
	}
	
}