// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item.h"
#include "DrawDebugHelpers.h"
#include "Slasher/Slasher.h"

// Sets default values
AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AItem::BeginPlay()
{
	Super::BeginPlay();
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Automatically move forward
	// const float MovementSpeed = 50.f;
	// AddActorWorldOffset(GetActorForwardVector() * MovementSpeed * DeltaTime);

	UWorld* World = GetWorld();
	
	FVector Forward=  GetActorForwardVector();

	if (World)
	{
		const FVector Location = GetActorLocation();
		
		DRAW_POINT(Location);
		DRAW_DEBUG_FORWARD_LINE(Location);
		DRAW_DEBUG_ORIGIN_LINE(Location);
		DRAW_SPHERE(Location);
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
