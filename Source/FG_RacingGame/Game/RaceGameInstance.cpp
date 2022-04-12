#include "RaceGameInstance.h"

void URaceGameInstance::Init()
{
	Super::Init();
	UE_LOG(LogTemp, Log, TEXT("URACEGAMEINSTANCE::INIT CALLED WOOHOO"));
}

URaceGameInstance* URaceGameInstance::Get(UObject* WorldContext)
{
	UWorld* World = WorldContext->GetWorld();
	return World->GetGameInstance<URaceGameInstance>();
}

int URaceGameInstance::CoolThing(size_t x, size_t y, size_t z)
{
	return 0;
}
