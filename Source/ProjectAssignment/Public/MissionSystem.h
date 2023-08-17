#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Mission.h"
#include "MissionSystem.generated.h"

UCLASS()
class PROJECTASSIGNMENT_API UMissionSystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UMissionSystem();
	UFUNCTION(BlueprintCallable)
	FMission GetMissionDataByRow(FName RowName);

private:
	UDataTable* m_MissionDataTable;
	
};



