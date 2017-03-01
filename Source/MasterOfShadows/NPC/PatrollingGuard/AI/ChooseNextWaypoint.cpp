// Fill out your copyright notice in the Description page of Project Settings.

#include "MasterOfShadows.h"
#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "NPC/PatrollingGuard/AI/PatrolRoute.h"




EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);

	auto PatrolPoints = GetPatrolPoints(OwnerComp);

	// Protect against empty patrol points
	if (PatrolPoints.Num() == 0) 
	{ 
		UE_LOG(LogTemp, Warning, TEXT("UChooseNextWaypoint::ExecuteTask - No Patrol Points selected!"));
		return EBTNodeResult::Failed; 
	}

	SetNextWaypoint(PatrolPoints, BlackboardComp);
	CycleIndex(PatrolPoints, BlackboardComp);

	//UE_LOG(LogTemp, Warning, TEXT("Waypoint Index: %i"), Index);
	return EBTNodeResult::Succeeded;
}

TArray<AActor*> UChooseNextWaypoint::GetPatrolPoints(UBehaviorTreeComponent& OwnerComp) const
{
	auto AIController = OwnerComp.GetAIOwner();
	auto Owner = AIController->GetPawn();
	auto PatrolRouteComponent = Owner->FindComponentByClass<UPatrolRoute>();

	// Protect again no patrol route component
	if (!ensure(PatrolRouteComponent)) { return TArray<AActor*>(); }
	
	return PatrolRouteComponent->GetPatrolPoints();
}

void UChooseNextWaypoint::SetNextWaypoint(TArray<AActor*> PatrolPoints, UBlackboardComponent* BlackBoardComp)
{
	if (PatrolPoints.Num() == 0) { return; }
	auto Index = BlackBoardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackBoardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);
}

void UChooseNextWaypoint::CycleIndex(TArray<AActor*> PatrolPoints, UBlackboardComponent* BlackBoardComp)
{
	auto Index = BlackBoardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	auto NextIndex = (Index + 1) % PatrolPoints.Num();
	BlackBoardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);
}
