// Copyright Jackk


#include "Actor/CakeEffectActor.h"

// Sets default values
ACakeEffectActor::ACakeEffectActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACakeEffectActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACakeEffectActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

