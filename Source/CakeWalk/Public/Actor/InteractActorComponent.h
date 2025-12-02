// Copyright Jackk

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractInterface.h"

#include "InteractActorComponent.generated.h"

class USceneComponent;
class USphereComponent;
class UWidgetComponent;
class UUserWidget;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CAKEWALK_API UInteractActorComponent : public UActorComponent, public IInteractInterface
{
	GENERATED_BODY()

public:	
	UInteractActorComponent();
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/*InteractInterface*/
	virtual void ShowPickupWidget_Implementation(bool bShowWidget) override;
	virtual void EnableCustomDepth_Implementation(bool bEnable) override;
	/*End InteractInterface*/ 

	FORCEINLINE USceneComponent* GetInteractRoot() const { return InteractRoot; }

	UFUNCTION()
	void OnSphereOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

protected:
	virtual void BeginPlay() override;


private:
	UPROPERTY()
	TObjectPtr<USceneComponent> InteractRoot;

	UPROPERTY(VisibleAnywhere, Category = "Interactive Actor")
	TObjectPtr<USphereComponent> InteractSphere;

	UPROPERTY(VisibleAnywhere, Category = "Interactive Actor")
	TObjectPtr<UWidgetComponent> InteractWidget;
	UPROPERTY(EditDefaultsOnly, Category = "Interactive Actor")
	TSubclassOf<UUserWidget> InteractWidgetClass;


		
};
