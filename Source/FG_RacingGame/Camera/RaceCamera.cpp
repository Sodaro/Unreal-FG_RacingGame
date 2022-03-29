#include "RaceCamera.h"
#include "Camera/CameraComponent.h"
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
	LocationOffset = FollowActor->GetActorLocation() - GetActorLocation();
}

void ARaceCamera::Tick(float DeltaTime)
{
	FVector Location = GetActorLocation();
	Location = FMath::Lerp(Location, FollowActor->GetActorLocation() - LocationOffset, FollowSpeed * DeltaTime);
	SetActorLocation(Location);
}
