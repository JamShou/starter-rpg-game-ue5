#pragma once

UENUM(BlueprintType)
enum class ECharacterState : uint8
{
	ECS_Unequipped UMETA(DisplayName = "Unequipped"),
	ECS_EquippedOneHandedWeapon UMETA(DisplayName = "Equipped 1h Weapon"),
	ECS_EquippedTwoHandedWeapon UMETA(DisplayName = "Equipped 2h Weapon")
};