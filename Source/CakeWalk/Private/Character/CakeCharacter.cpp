// Copyright Jackk


#include "Character/CakeCharacter.h"
#include "Weapon/Weapon.h"
#include <Net/UnrealNetwork.h>

ACakeCharacter::ACakeCharacter()
{
}

void ACakeCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ACakeCharacter, OverlappingWeapon);
}

void ACakeCharacter::SetOverlappingWeapon(AWeapon* OverlapWeapon)
{
	if (OverlappingWeapon) {
		OverlappingWeapon->ShowPickupWidget(false);
	}
	OverlappingWeapon = OverlapWeapon;
	if (IsLocallyControlled()) {
		if (OverlappingWeapon) {
			OverlappingWeapon->ShowPickupWidget(true);
		}
	}
}

void ACakeCharacter::OnRep_OverlappingWeapon(AWeapon* LastWeapon)
{
	if (OverlappingWeapon) {
		OverlappingWeapon->ShowPickupWidget(true);
	}
	if (LastWeapon)
	{
		LastWeapon->ShowPickupWidget(false);
	}
}

