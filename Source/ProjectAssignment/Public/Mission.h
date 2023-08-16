// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Mission.generated.h"


/**
 * 
 */
class PROJECTASSIGNMENT_API Mission
{
public:
	Mission();
	~Mission();
};


UENUM(BlueprintType)
enum class EMissionType
{
	COLLECT_SPECIFIC_ITEM,
	COLLECT_SPECIFIC_CATEGORY,
	ACTION_BASED 
};

USTRUCT(BlueprintType)
struct FMission 
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
        EMissionType MissionType;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
        FString MissionDescription;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
        FString MissionObjective;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
        int MissionValue;
};