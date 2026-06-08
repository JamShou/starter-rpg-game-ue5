// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class SLASHER_API AItem : public AActor
{
	GENERATED_BODY()

public:
	AItem();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Amplitude = 0.25f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TimeConstant = 5.f;

	UFUNCTION(BlueprintPure)
	float TransformedSin();

	UFUNCTION(BlueprintPure)
	float TransformedCosin();

	template <typename T>
	T Avg(T First, T Second);

private:
	UPROPERTY(VisibleAnywhere)
	float RunningTime;
};

template <typename T>
inline T AItem::Avg(T First, T Second)
{
	return (First + Second) / 2;
}
