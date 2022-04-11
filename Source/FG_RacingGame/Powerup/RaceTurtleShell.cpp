#include "RaceTurtleShell.h"
#include "Components/SphereComponent.h"
#include "../Player/RaceCar.h"
ARaceTurtleShell::ARaceTurtleShell()
{
	PrimaryActorTick.bCanEverTick = true;

	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	RootComponent = Collision;
}

void ARaceTurtleShell::BeginPlay()
{
	Super::BeginPlay();
	ShellVelocity = GetActorForwardVector() * 1500.f;
}

void ARaceTurtleShell::Tick(float DeltaTime)
{
	FHitResult Hit;
	AddActorWorldOffset(ShellVelocity * DeltaTime, true, &Hit);

	if (Hit.bBlockingHit)
	{
		if (Hit.Actor->IsA<ARaceCar>())
		{
			Hit.Actor->Destroy();
			Destroy();
			return;
		}

		if (Hit.bStartPenetrating)
		{
			AddActorWorldOffset(Hit.Normal * Hit.PenetrationDepth + 0.01f);
		}
		ShellVelocity = ShellVelocity.MirrorByVector(Hit.Normal);
	}
		
}
