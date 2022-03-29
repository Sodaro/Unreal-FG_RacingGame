#pragma once
#include "GameFramework/Actor.h"
#include "RaceCamera.generated.h"

class UCameraComponent;

UCLASS()
class ARaceCamera : public AActor
{
	GENERATED_BODY()

	FVector LocationOffset;
public:
	ARaceCamera();

	void BeginPlay() override;
	void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;

	UPROPERTY(EditINstanceOnly, Category = "Camera Follow")
	AActor* FollowActor;

	UPROPERTY(EditAnywhere, Category = "Camera Follow|Advanced")
	float FollowSpeed = 5.f;
};