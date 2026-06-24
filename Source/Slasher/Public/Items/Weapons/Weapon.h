// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/Item.h"
#include "Weapon.generated.h"

/**
 * 
 */
UCLASS()
class SLASHER_API AWeapon : public AItem
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaTime) override;
	
protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsEquipped = false;
	
};
