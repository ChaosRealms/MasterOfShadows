// Fill out your copyright notice in the Description page of Project Settings.

#include "MasterOfShadows.h"
#include "PatrollingGuard.h"
#include "Weapons//Gun/Gun.h"


// Sets default values
APatrollingGuard::APatrollingGuard()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APatrollingGuard::BeginPlay()
{
	Super::BeginPlay();

	/*if (GunClass)
	{
		Gun = GetWorld()->SpawnActor<AGun>(GunClass, GetActorLocation(), GetActorRotation());
		Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint_0"));
		Gun->SetAnimInstance(GetMesh()->GetAnimInstance());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Warning: GunClass is empty!"));
	}*/
	
}

// Called every frame
void APatrollingGuard::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void APatrollingGuard::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

AGun* APatrollingGuard::GetGun() const
{
	if (!ensure(Gun)) { return nullptr; }
	return Gun;
}

