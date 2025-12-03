// Copyright Jackk

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon/WeaponTypes.h"

#include "Weapon.generated.h"


class ACakeCharacter;
class ACakePlayerController;
class ACasing;
class USphereComponent;
class UWidgetComponent;

UENUM(BlueprintType)
enum class EWeaponState : uint8 {
	EWS_Initial UMETA(DisplayName = "Initial State"),
	EWS_Equipped UMETA(DisplayName = "Equipped"),
	EWS_EquippedSecondary UMETA(DisplayName = "Equipped Secondary"),
	EWS_Dropped UMETA(DisplayName = "Dropped"),

	EWS_Max UMETA(DisplayName = "DefaultMAX")
};

UENUM(BlueprintType)
enum class EFireType : uint8 {
	EFT_HitScan UMETA(DisplayName = "Hit Scan Weapon"),
	EFT_Projectile UMETA(DisplayName = "Projectile Weapon"),
	EFT_Shotgun UMETA(DisplayName = "Shotgun Weapon"),

	EFT_MAX UMETA(DisplayName = "DefaultMAX")
};

UCLASS()
class CAKEWALK_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	AWeapon();
	//virtual void Tick(float DeltaTime) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	//virtual void OnRep_Owner() override;
	void SetHUDAmmo();
	void ShowPickupWidget(bool bShowWidget);
	virtual void Fire(const FVector& HitTarget);
	virtual void Dropped();
	void AddAmmo(int32 AmmoToAdd);

	void  SetWeaponState(EWeaponState State);
	FORCEINLINE TObjectPtr<USphereComponent> GetAreaSphere() const { return AreaSphere; }
	FORCEINLINE TObjectPtr<UWidgetComponent> GetPickupWidget() const { return PickupWidget; }

	FORCEINLINE TObjectPtr<USkeletalMeshComponent> GetWeaponMesh() const { return WeaponMesh; }
	virtual float GetZoomedFOV() const;
	FORCEINLINE float GetZoomInterpSpeed() const { return ZoomInterpSpeed; }
	bool IsEmpty();
	bool IsFull();
	FORCEINLINE EWeaponType GetWeaponType() const { return WeaponType; }
	FORCEINLINE int32 GetAmmo() const { return Ammo; }
	FORCEINLINE int32 GetMagCapacity() const { return MagCapacity; }
	FORCEINLINE float GetDamage() const { return Damage; }
	FORCEINLINE float GetHeadShotDamage() const { return HeadShotDamage; }


	/* Textures for the weapon crosshairs */
	UPROPERTY(EditAnywhere, Category = Crosshairs)
	TObjectPtr<UTexture2D> CrosshairsCenter;
	UPROPERTY(EditAnywhere, Category = Crosshairs)
	TObjectPtr<UTexture2D> CrosshairsLeft;
	UPROPERTY(EditAnywhere, Category = Crosshairs)
	TObjectPtr<UTexture2D> CrosshairsRight;
	UPROPERTY(EditAnywhere, Category = Crosshairs)
	TObjectPtr<UTexture2D> CrosshairsTop;
	UPROPERTY(EditAnywhere, Category = Crosshairs)
	TObjectPtr<UTexture2D> CrosshairsBottom;

	UPROPERTY(EditAnywhere)
	float ZoomedFOV = 30.f;
	UPROPERTY(EditAnywhere)
	float ZoomInterpSpeed = 20.f;

	UPROPERTY(EditAnywhere, Category = Combat)
	float FireDelay = .15f;

	UPROPERTY(EditAnywhere, Category = Combat)
	bool bAutomatic = true;

	UPROPERTY(EditAnywhere)
	TObjectPtr<USoundCue> EquipSound;
	

	void EnableCustomDepth(bool bEnable);


	UPROPERTY(EditAnywhere)
	EFireType FireType;

	UPROPERTY(EditAnywhere, Category = "Weapon Scatter")
	bool bUseScatter = false;

	//for shotgun
	FVector TraceEndWithScatter(const FVector& HitTarget);

	UPROPERTY(EditAnywhere, Category = "Weapon Scatter")
	float DistanceToSphere = 800.f;

	UPROPERTY(EditAnywhere, Category = "Weapon Scatter")
	float SphereRadius = 75.f;

	UPROPERTY(EditAnywhere)
	float Damage = 20.f;

	UPROPERTY(EditAnywhere)
	float HeadShotDamage = 40.f;


protected:
	virtual void BeginPlay() override;
	virtual void OnWeaponStateSet();
	virtual void OnEquipped();
	virtual void OnEquippedSecondary();
	virtual void OnDropped();

	UFUNCTION()
	virtual void OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	virtual void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY()
	TObjectPtr<ACakeCharacter> OwnerCharacter;
	UPROPERTY()
	TObjectPtr<ACakePlayerController> OwnerController;

private:
	UPROPERTY(EditAnywhere, Category = "Weapon Properties")
	TObjectPtr<USkeletalMeshComponent> WeaponMesh;

	UPROPERTY(VisibleAnywhere, Category = "Weapon Properties")
	TObjectPtr<USphereComponent> AreaSphere;

	UPROPERTY(ReplicatedUsing = OnRep_WeaponState, VisibleAnywhere, Category = "Weapon Properties")
	EWeaponState WeaponState;

	UFUNCTION()
	void OnRep_WeaponState();

	UPROPERTY(VisibleAnywhere, Category = "Weapon Properties")
	TObjectPtr<UWidgetComponent> PickupWidget;

	UPROPERTY(EditAnywhere, Category = "Weapon Properties")
	TObjectPtr<UAnimationAsset> FireAnimation;

	//UPROPERTY(EditAnywhere)
	//TSubclassOf<ACasing> CasingClass;

	UPROPERTY(EditAnywhere)
	int32 Ammo;

	UFUNCTION(Client, Reliable)
	void ClientUpdateAmmo(int32 ServerAmmo);

	UFUNCTION(Client, Reliable)
	void ClientAddAmmo(int32 AmmoToAdd);

	void SpendRound();

	UPROPERTY(EditAnywhere)
	int32 MagCapacity;

	// The number of unprocessed server requests for Ammo.
	// Incremented in SpendRound, decremented in ClientUpdateAmmo.
	int32 Sequence = 0;

	UPROPERTY(EditAnywhere)
	EWeaponType WeaponType;

};
