#include "MissionManager.h"

#include <string>

#include "ItemStruct.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Logging/StructuredLog.h"
#include "Misc/OutputDeviceNull.h"


UMissionManager::UMissionManager()
{
	this->LevelMissionTable = LoadObject<UDataTable>(nullptr,
		TEXT("DataTable'/Game/DataTable/LevelMissionTable.LevelMissionTable'"));
}

TArray<FMission> UMissionManager::GetMissionDataByRow(FName RowName)
{
	return LevelMissionTable->FindRow<FLevelMission>(RowName, "")->LevelMissionList;
}

bool UMissionManager::InitializeLevelMissionInStage(FName Level)
{

	if (!CurrentLevelMission.IsEmpty())
		return false;
	
	CurrentLevelMission = LevelMissionTable->FindRow<FLevelMission>(Level, "")->LevelMissionList;
	return true;

}

void UMissionManager::DeinitializeLevelMissionInStage()
{
	CurrentLevelMission = TArray<FMission>();
	HUDDisplay = nullptr;
}

TArray<FMission> UMissionManager::GetCurrentLevelMission()
{
	return CurrentLevelMission;
}


TArray<FMission> UMissionManager::CheckStealItem(FGameItem gameItem)
{
	TArray<FMission> missionDone = TArray<FMission>();

	// Go through all level mission to check if game item satisfy the mission
	for (int m = 0; m < CurrentLevelMission.Num(); m++)
	{
		FMission mission = CurrentLevelMission[m];
		
		if (mission.Completed)
			continue;
		
		// Check if category mission
		if (mission.MissionType == EMissionType::COLLECT_SPECIFIC_CATEGORY &&
			mission.MissionObjective.IsEqual(UEnum::GetValueAsName(gameItem.itemCategory)))
		{
			mission.Completed = true;
			missionDone.Add(mission);
		}

		// Check if item mission
		else if (mission.MissionType == EMissionType::COLLECT_SPECIFIC_ITEM &&
			mission.MissionObjective.IsEqual(gameItem.itemName))
		{
			mission.Completed = true;
			missionDone.Add(mission);

		}

		CurrentLevelMission[m] = mission;
	}

	// Ping update display if completed mission
	if (missionDone.Num() > 0)
	{
		UpdateMissionDisplay();
	}

	return missionDone;
}

TArray<FMission> UMissionManager::CheckDoActionMission(FName ActionName)
{
	TArray<FMission> missionDone = TArray<FMission>();

	// Go through all level mission to check if game item satisfy the mission
	for (int m = 0; m < CurrentLevelMission.Num(); m++)
	{
		FMission mission = CurrentLevelMission[m];

		if (mission.Completed || mission.MissionType != EMissionType::ACTION_BASED)
			continue;


		// Check if category mission
		if (mission.MissionObjective.IsEqual(ActionName))
		{
			mission.Completed = true;
			missionDone.Add(mission);
		}
		CurrentLevelMission[m] = mission;
	}

	if (missionDone.Num() > 0)
	{
		UpdateMissionDisplay();
	}
	
	return missionDone;

}

void UMissionManager::RegisterHUDDisplay(UObject* uObject)
{
	HUDDisplay = uObject;
}

void UMissionManager::UpdateMissionDisplay() const
{
	if (!HUDDisplay)
		return;
	
	FOutputDeviceNull ar;
	HUDDisplay->CallFunctionByNameWithArguments(TEXT("UpdateMissionDisplay"), ar, nullptr, true);
}




