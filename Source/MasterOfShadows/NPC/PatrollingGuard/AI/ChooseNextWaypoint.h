// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/BTTaskNode.h"
#include "ChooseNextWaypoint.generated.h"

class UBlackboardComponent;

/**
 * 
 */
UCLASS()
class MASTEROFSHADOWS_API UChooseNextWaypoint : public UBTTaskNode
{
	GENERATED_BODY()
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:

	UPROPERTY(EditAnywhere, Category = "Blackboard")
		struct FBlackboardKeySelector IndexKey;

		UPROPERTY(EditAnywhere, Category = "Blackboard")
		struct FBlackboardKeySelector WaypointKey;

private:

	TArray<AActor*> GetPatrolPoints(UBehaviorTreeComponent& OwnerComp) const;

	void SetNextWaypoint(TArray<AActor*> PatrolPoints, UBlackboardComponent* BlackBoardComp);

	void CycleIndex(TArray<AActor*> PatrolPoints, UBlackboardComponent* BlackBoardComp);

};
