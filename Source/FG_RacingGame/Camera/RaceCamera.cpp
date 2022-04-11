#include "RaceCamera.h"
#include "Camera/CameraComponent.h"
#include "../Game/RaceGameInstance.h"
#include "../Player/RaceCar.h"
ARaceCamera::ARaceCamera()
{
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(Root);
	PrimaryActorTick.bCanEverTick = true;

	
}

void ARaceCamera::BeginPlay()
{
	Super::BeginPlay();
	APlayerController* Controller = GetWorld()->GetFirstPlayerController();
	Controller->SetViewTarget(this);
	if (FollowActor == nullptr)
		return;
	//LocationOffset = FollowActor->GetActorLocation() - GetActorLocation();
	//for (TActorIterator<ARaceCar> It(GetWorld()); It; ++It)
	//{

	//}

}

void ARaceCamera::Tick(float DeltaTime)
{

	int NumCars = 0;
	FVector LocationSum = FVector::ZeroVector;
	URaceGameInstance* GameInstance = URaceGameInstance::Get(this);

	for (ARaceCar* Car : GameInstance->Cars)
	{
		LocationSum += Car->GetActorLocation();
		NumCars++;
	}
	if (NumCars == 0)
		return;

	FVector TargetLocation = LocationSum / NumCars;
	//if (FollowActor == nullptr)
	//	return;

	FVector Location = GetActorLocation();
	Location = FMath::Lerp(Location, TargetLocation, FollowSpeed * DeltaTime);
	SetActorLocation(Location);
}
