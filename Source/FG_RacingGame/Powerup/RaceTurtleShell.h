#pragma once

#include "GameFramework/Actor.h"
#include "RaceTurtleShell.generated.h"

class USphereComponent;

UCLASS()
class ARaceTurtleShell : public AActor
{
	GENERATED_BODY()

public:
	ARaceTurtleShell();

	void BeginPlay() override;
	void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	USphereComponent* Collision;

	FVector ShellVelocity;
};