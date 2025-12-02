// Copyright Jackk


#include "Actor/InteractActorComponent.h"
#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"
#include "Character/CakeCharacter.h"

UInteractActorComponent::UInteractActorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	InteractRoot = CreateDefaultSubobject<USceneComponent>(TEXT("InteractRoot"));

	InteractSphere = CreateDefaultSubobject<USphereComponent>(TEXT("InteractionSphere"));
	InteractSphere->SetupAttachment(InteractRoot);
	InteractSphere->SetSphereRadius(100.f);
	InteractSphere->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	InteractSphere->SetCollisionResponseToAllChannels(ECR_Ignore);
	InteractSphere->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	InteractWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("InteractionWidget"));
	InteractWidget->SetupAttachment(InteractRoot);

}

void UInteractActorComponent::ShowPickupWidget_Implementation(bool bShowWidget)
{
	if(IsValid(InteractWidget))
	{
		InteractWidget->SetVisibility(bShowWidget);
	}
}

void UInteractActorComponent::EnableCustomDepth_Implementation(bool bEnable)
{
	if(IInteractInterface* Interactable = Cast<IInteractInterface>(GetOwner()))
	{
		Interactable->Execute_EnableCustomDepth(GetOwner(), bEnable);
	}
}

void UInteractActorComponent::OnSphereOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(ACakeCharacter* CakeCharacter = Cast<ACakeCharacter>(OtherActor))
	{
		if(GetOwner()->Implements<UInteractInterface>())
		{
			CakeCharacter->SetOverlappingInteractable(GetOwner());
		}
	}
}

void UInteractActorComponent::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if(ACakeCharacter* CakeCharacter = Cast<ACakeCharacter>(OtherActor))
	{
		if(GetOwner()->Implements<UInteractInterface>())
		{
			CakeCharacter->SetOverlappingInteractable(nullptr);
		}
	}
}


void UInteractActorComponent::BeginPlay()
{
	Super::BeginPlay();

	InteractSphere->OnComponentBeginOverlap.AddDynamic(this, &UInteractActorComponent::OnSphereOverlap);
	InteractSphere->OnComponentEndOverlap.AddDynamic(this, &UInteractActorComponent::OnSphereEndOverlap);

	
}

//void UInteractActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
//{
//	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
//
//}

