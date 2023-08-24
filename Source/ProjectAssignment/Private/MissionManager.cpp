#include "MissionManager.h"

#include <string>

#include "ItemStruct.h"
#include "Kismet/KismetSystemLibrary.h"
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

bool UMissionManager::DeinitializeLevelMissionInStage()
{
	CurrentLevelMission = TArray<FMission>();
	HUDDisplay = nullptr;
	
	return true;
}

TArray<FMission> UMissionManager::GetCurrentLevelMission()
{
	return CurrentLevelMission;
}


bool UMissionManager::CheckStealItem(FGameItem gameItem)
{
	for (FMission mission : CurrentLevelMission)
	{
		if (mission.Completed)
			continue;
		
		// Check if category mission
		if (mission.MissionType == EMissionType::COLLECT_SPECIFIC_CATEGORY &&
			mission.MissionObjective.IsEqual(UEnum::GetValueAsName(gameItem.itemCategory)))
		{
			mission.Completed = true;
			// Ping update display
			return true;
		}

		// Check if item mission
		else if (mission.MissionType == EMissionType::COLLECT_SPECIFIC_ITEM &&
			mission.MissionObjective.IsEqual(gameItem.itemName))
		{
			mission.Completed = true;
			UpdateMissionDisplay();
			return true;
		}
	}
	// If not found any matching mission
	return false;
}

bool UMissionManager::CheckDoActionMission(FName ActionName)
{
	for (FMission mission : CurrentLevelMission)
	{
		if (mission.Completed && mission.MissionType != EMissionType::ACTION_BASED)
			continue;
		
		// Check if category mission
		if (mission.MissionObjective.IsEqual(ActionName))
		{
			mission.Completed = true;
			UpdateMissionDisplay();
			return true;
		}
	}


	
	// If not found any matching mission
	return false;
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




