// Copyright Jackk

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "InteractiveActor.generated.h"


class USphereComponent;
class UWidgetComponent;


UCLASS()
class CAKEWALK_API AInteractiveActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AInteractiveActor();

	void EnableCustomDepth(bool bEnable);

	UFUNCTION()
	void OnSphereOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

protected:
	virtual void BeginPlay() override;


private:
	UPROPERTY(EditAnywhere, Category = "Interactive Actor")
	TObjectPtr<USkeletalMeshComponent> InteractiveMesh;

	UPROPERTY(EditAnywhere, Category = "Interactive Actor")
	TObjectPtr<USphereComponent> InteractiveSphere;

	UPROPERTY(EditAnywhere, Category = "Interactive Actor")
	TObjectPtr<UWidgetComponent> InteractiveWidget;


};
