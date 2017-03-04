// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "PatrollingGuard.generated.h"

class AGun;

UCLASS()
class MASTEROFSHADOWS_API APatrollingGuard : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APatrollingGuard();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	AGun* Gun;

public:

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	TSubclassOf<AGun> GunClass;

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	AGun* GetGun() const;

	
	
};
