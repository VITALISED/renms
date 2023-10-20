#pragma once
#include <metadata/metadata_common.h>

class cGcMissionConditionInSeasonalUA
{
    static unsigned long long muNameHash = 0x15FCC555BAF3FC21;
    static unsigned long long muTemplateHash = 0xE56B9FAF2C3575E4;

    int miSpecificRendevousPlanetIndex;
    bool mbSpecificIndexOnlyNeedsToMatchSystem;
    bool mbTakeIndexFromSeasonData;
    bool mbTakeIndexFromMilestoneStage;
    bool mbCompleteIfRendezvousDone;
}
