#include "Items/Item.h"

#include "BlendSpaceAnalysis.h"
#include "ViewportInteractionTypes.h"
#include "Slasher/DebugMacros.h"

AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = true;
	
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
	RootComponent = ItemMesh;
}

void AItem::BeginPlay()
{
	Super::BeginPlay();
	
	int32 averageInt = Avg<int32>(1,3);
	UE_LOG(LogTemp,Warning, TEXT("Avg of 1 and 3 is: %d"), averageInt);
	
}

float AItem::TransformedSin()
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}

float AItem::TransformedCosin()
{
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UWorld* World = GetWorld();
	FVector Forward=  GetActorForwardVector();
	
	RunningTime += DeltaTime;
	float DeltaZ = TransformedSin();
	AddActorWorldOffset(FVector(0,0,DeltaZ));

	FRotator DeltaRotation(0.f, 30.f * DeltaTime, 0.f);
	AddActorLocalRotation(DeltaRotation);
}
