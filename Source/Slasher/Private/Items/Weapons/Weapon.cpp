// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Weapons/Weapon.h"

void AWeapon::Tick(float DeltaTime)
{
	AActor::Tick(DeltaTime);

	if (IsEquipped)
	{
		return;
	}

	RunningTime += DeltaTime;
	float DeltaZ = TransformedSin();
	AddActorWorldOffset(FVector(0,0,DeltaZ));
	
	FRotator DeltaRotation(0.f, 30.f * DeltaTime, 0.f);
	AddActorLocalRotation(DeltaRotation);
}

