#pragma once
#include <metadata/metadata_common.h>

class cGcMissionConditionIsPartyPlanetUnlocked
{
    static unsigned long long muNameHash = 0xD08AEA33ACABB2E9;
    static unsigned long long muTemplateHash = 0x4577DB384FD71892;

    int miSpecificRendevousPlanetIndex;
    bool mbTakeIndexFromSeasonData;
    bool mbTakeIndexFromMilestoneStage;
}
