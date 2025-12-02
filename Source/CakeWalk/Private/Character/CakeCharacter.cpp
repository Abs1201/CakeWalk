// Copyright Jackk


#include "Character/CakeCharacter.h"
#include <Actor/InteractInterface.h>
#include <Net/UnrealNetwork.h>



void ACakeCharacter::SetOverlappingInteractable(AActor* InteractableActor)
{
	if(IInteractInterface* Interactable = Cast<IInteractInterface>(InteractableActor))
	{
		Interactable->Execute_ShowPickupWidget(OverlappingInteractableActor, false);
	}
	OverlappingInteractableActor = InteractableActor;
	if (IsLocallyControlled())
	{
		if(OverlappingInteractableActor)
		{
			if(IInteractInterface* Interactable = Cast<IInteractInterface>(OverlappingInteractableActor))
			{
				Interactable->Execute_ShowPickupWidget(OverlappingInteractableActor, true);
			}
		}
	}
}

void ACakeCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(ACakeCharacter, OverlappingInteractableActor, COND_AutonomousOnly);
}

void ACakeCharacter::OnRep_OverlappingInteractable(AActor* LastInteractableActor)
{
	if(OverlappingInteractableActor)
	{
		if(IInteractInterface* Interactable = Cast<IInteractInterface>(OverlappingInteractableActor))
		{
			Interactable->Execute_ShowPickupWidget(OverlappingInteractableActor, true);
		}
	}
	if(LastInteractableActor)
	{
		if(IInteractInterface* Interactable = Cast<IInteractInterface>(LastInteractableActor))
		{
			Interactable->Execute_ShowPickupWidget(OverlappingInteractableActor, false);
		}
	}
}
