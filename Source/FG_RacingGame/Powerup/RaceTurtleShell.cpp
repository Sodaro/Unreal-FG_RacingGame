#include "RaceTurtleShell.h"
#include "Components/SphereComponent.h"

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
		ShellVelocity = ShellVelocity.MirrorByVector(Hit.Normal);
}
