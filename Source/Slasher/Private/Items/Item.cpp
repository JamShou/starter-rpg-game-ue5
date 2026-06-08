// Fill out your copyright notice in the Description page of Project Settings.

#include "Items/Item.h"

#include "BlendSpaceAnalysis.h"
#include "ViewportInteractionTypes.h"
#include "Slasher/DebugMacros.h"

// Sets default values
AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = true;
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
	
	if (World)
	{
		const FVector Location = GetActorLocation();
		DRAW_SPHERE_SingleFrame(Location);
		DRAW_VECTOR_SingleFrame(Location, Location + GetActorForwardVector());
	}

	// UE_LOG(LogTemp, Log, TEXT("DeltaTime: %f"), DeltaTime);

	// if (GEngine)
	// {
	// 	FString Name = GetName();
	// 	FString Message = FString::Printf(TEXT("Item Name: %s"), *Name);
	// 	GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Green, Message);
	//
	// 	//UE_LOG(LogTemp, Warning, TEXT("Item Name: %s"), *Name);
	// }
}
