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
	UE_LOG(LogTemp, Warning, TEXT("Warning Log Example for Slasher"));
	UE_LOG(LogTemp, Error, TEXT("Error Log Example"));
	UE_LOG(LogTemp, Log, TEXT("Regular Log Example"));

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Magenta, TEXT("DEBUG FROM CONSOLE"));
	}
	UWorld* World = GetWorld();

	if (World)
	{
		UE_LOG(LogTemp, Log, TEXT("Drawing Sphere"));
		FVector Location = GetActorLocation();
		DRAW_SPHERE(Location);
	}
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// UE_LOG(LogTemp, Log, TEXT("DeltaTime: %f"), DeltaTime);

	if (GEngine)
	{
		FString Name = GetName();
		FString Message = FString::Printf(TEXT("Item Name: %s"), *Name);
		GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Green, Message);

		//UE_LOG(LogTemp, Warning, TEXT("Item Name: %s"), *Name);
	}
}
