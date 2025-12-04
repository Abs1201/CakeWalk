// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/CakeCharacterBase.h"


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

