#include "RaceTurtleShellPowerup.h"
#include "RaceTurtleShell.h"

void URaceTurtleShellPowerup::OnPowerupActivated_Implementation()
{
	FTransform SpawnTransform = GetOwner()->GetActorTransform();
	SpawnTransform.AddToTranslation(GetOwner()->GetActorForwardVector() * SpawnOffset);

	GetWorld()->SpawnActor(TurtleClass, &SpawnTransform);
}