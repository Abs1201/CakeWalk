// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/CakeCharacterBase.h"
#include "AbilitySystemComponent.h"


ACakeCharacterBase::ACakeCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;


}

void ACakeCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACakeCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACakeCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UAbilitySystemComponent* ACakeCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* ACakeCharacterBase::GetAttributeSet() const
{
	return AttributeSet;
}

