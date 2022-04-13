#pragma once
#include "GameFramework/Actor.h"
#include "RaceStartLine.generated.h"

class ARaceCar;

UCLASS()
class ARaceStartLine : public AActor
{
	GENERATED_BODY()
public:
	ARaceStartLine();

	void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(EditDefaultsOnly, Category = Race)
	TSubclassOf<ARaceCar> CarClass;

	UPROPERTY(EditInstanceOnly)
	int32 NumberOfPlayers = 1;
};