// Copyright Jackk

#pragma once

#include "CoreMinimal.h"
#include "Character/CakeCharacterBase.h"

#include "CakeCharacter.generated.h"


class AWeapon;

/**
 * 
 */
UCLASS()
class CAKEWALK_API ACakeCharacter : public ACakeCharacterBase
{
	GENERATED_BODY()

public:
	ACakeCharacter();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;


	void SetOverlappingWeapon(AWeapon* OverlapWeapon);
	

private:
	UPROPERTY(ReplicatedUsing = OnRep_OverlappingWeapon)
	TObjectPtr<AWeapon> OverlappingWeapon;

	UFUNCTION()
	void OnRep_OverlappingWeapon(AWeapon* LastWeapon);
};
