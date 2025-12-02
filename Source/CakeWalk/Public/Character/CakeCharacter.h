// Copyright Jackk

#pragma once

#include "CoreMinimal.h"
#include "Character/CakeCharacterBase.h"

#include "CakeCharacter.generated.h"



/**
 * 
 */
UCLASS()
class CAKEWALK_API ACakeCharacter : public ACakeCharacterBase
{
	GENERATED_BODY()

public:
	void SetOverlappingInteractable(AActor* InteractableActor);
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
	UPROPERTY(ReplicatedUsing = OnRep_OverlappingInteractable)
	AActor* OverlappingInteractableActor;

	UFUNCTION()
	void OnRep_OverlappingInteractable(AActor* LastInteractableActor);

	
};
