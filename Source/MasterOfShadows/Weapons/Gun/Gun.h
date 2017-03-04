// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Gun.generated.h"

class AProjectile;
class UAnimMontage;
class UAnimInstance;
class USoundBase;
class USkeletalMeshComponent;
class USceneComponent;

UCLASS()
class MASTEROFSHADOWS_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	/** Fires a projectile. */
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void OnFire();

	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	USoundBase* FireSound;

	/** AnimMontage to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	UAnimMontage* FireAnimation;

	UFUNCTION(Category = "Animation")
	void SetAnimInstance( UAnimInstance* AnimInstance );

protected:

	/** AnimMontage to play each time we fire */
	UPROPERTY(VisibleAnywhere, Category = "Gameplay")
	UAnimInstance* AnimationInstance;

private:

	/** Gun mesh: 1st person view (seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category = "Mesh")
	USkeletalMeshComponent* FP_Gun;

	/** Location on gun mesh where projectiles should spawn. */
	UPROPERTY(VisibleDefaultsOnly, Category = "Mesh")
	USceneComponent* FP_MuzzleLocation;

	/** Projectile class to spawn */
	UPROPERTY(EditDefaultsOnly, Category = "Projectile")
	TSubclassOf<AProjectile> ProjectileClass;
	
	
};
