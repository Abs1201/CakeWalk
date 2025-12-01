// Copyright Jackk


#include "Actor/InteractiveActor.h"
#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"
#include "CakeWalk/CakeWalk.h"
#include "Character/CakeCharacter.h"


AInteractiveActor::AInteractiveActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;
	SetReplicateMovement(true);

	InteractiveMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("InteractiveMesh"));
	SetRootComponent(InteractiveMesh);
	InteractiveMesh->SetCustomDepthStencilValue(CUSTOM_DEPTH_TAN);
	EnableCustomDepth(false);

	InteractiveSphere = CreateDefaultSubobject<USphereComponent>(TEXT("InteractionSphere"));
	InteractiveSphere->SetupAttachment(RootComponent);
	InteractiveSphere->SetSphereRadius(100.f);
	InteractiveSphere->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	InteractiveSphere->SetCollisionResponseToAllChannels(ECR_Ignore);
	InteractiveSphere->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	InteractiveWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("InteractiveWidget"));
	InteractiveWidget->SetupAttachment(RootComponent);

}

void AInteractiveActor::BeginPlay()
{
	Super::BeginPlay();

	InteractiveSphere->OnComponentBeginOverlap.AddDynamic(this, &AInteractiveActor::OnSphereOverlap);
	InteractiveSphere->OnComponentEndOverlap.AddDynamic(this, &AInteractiveActor::OnSphereEndOverlap);

	if (IsValid(InteractiveWidget))
	{
		InteractiveWidget->SetVisibility(false);
	}

}


void AInteractiveActor::EnableCustomDepth(bool bEnable)
{
	if (InteractiveMesh)
	{
		InteractiveMesh->SetRenderCustomDepth(bEnable);
		InteractiveMesh->MarkRenderStateDirty();
	}
}

void AInteractiveActor::OnSphereOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<ACakeCharacter>(OtherActor))
	{
		EnableCustomDepth(true);

		if (IsValid(InteractiveWidget))
		{
			InteractiveWidget->SetVisibility(true);
		}
	}

}

void AInteractiveActor::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	EnableCustomDepth(false);
	if (IsValid(InteractiveWidget))
	{
		InteractiveWidget->SetVisibility(false);
	}
}

