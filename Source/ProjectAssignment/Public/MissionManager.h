#pragma once

#include "CoreMinimal.h"
#include "ItemStruct.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Mission.h"
#include "MissionManager.generated.h"

UCLASS()
class PROJECTASSIGNMENT_API UMissionManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UMissionManager();

	// ----- Lower Level Methods -----
	
	// Lower level call to get mission data from data table based on rowname (level number)
	UFUNCTION(BlueprintCallable)
	TArray<FMission> GetMissionDataByRow(FName RowName);

	// ----- Current Level Methods ------
	
	// When starting a new level, call this function to load current level mission
	UFUNCTION(BlueprintCallable)
	bool InitializeLevelMissionInStage(FName Level);

	// When moving away from current level, call this function to unload current level mission
	UFUNCTION(BlueprintCallable)
	bool DeinitializeLevelMissionInStage();

	// Gets array of Mission List on the current set level mission
	UFUNCTION(BlueprintCallable) 
	TArray<FMission> GetCurrentLevelMission();

	UFUNCTION(BlueprintCallable)
	TArray<FMission> CheckStealItem(FGameItem gameItem);

	UFUNCTION(BlueprintCallable)
	TArray<FMission> CheckDoActionMission(FName ActionName);

	UFUNCTION(BlueprintCallable)
	void RegisterHUDDisplay(UObject* uObject);
private:
	TSoftObjectPtr<UDataTable> LevelMissionTable;
	TArray<FMission> CurrentLevelMission;
	TSoftObjectPtr<UObject> HUDDisplay;

	void UpdateMissionDisplay() const;
};