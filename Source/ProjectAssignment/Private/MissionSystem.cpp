#include "MissionSystem.h"



UMissionSystem::UMissionSystem()
{
	m_MissionDataTable = LoadObject<UDataTable>(nullptr, TEXT("DataTable'/Game/DataTable/MissionTable.MissionTable'"));
}
FMission UMissionSystem::GetMissionDataByRow(FName RowName)
{
	if (!m_MissionDataTable)
	{
		UE_LOG(LogTemp, Error, TEXT("%s"), TEXT("No table found") );
		return FMission();
	}
	
	FMission* mission = m_MissionDataTable->FindRow<FMission>(RowName, TEXT("Mission Row not found"));
	return *mission;
}
