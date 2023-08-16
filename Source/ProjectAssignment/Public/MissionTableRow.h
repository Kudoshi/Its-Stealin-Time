// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Mission.h"
#include "MissionTableRow.generated.h"


/**
 * 
 */
USTRUCT(BlueprintType)
struct FMissionTableRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite) FMission Mission;
};

UCLASS()
class PROJECTASSIGNMENT_API UMissionDataTable : public UDataTable
{
	GENERATED_BODY()
};
