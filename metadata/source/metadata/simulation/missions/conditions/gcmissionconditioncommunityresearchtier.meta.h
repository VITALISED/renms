#pragma once
#include <metadata/metadata_common.h>
#include <metadata/tkequalityenum.meta.h>

class cGcMissionConditionCommunityResearchTier
{
    static unsigned long long muNameHash = 0x2CFD4438CD6B0BDC;
    static unsigned long long muTemplateHash = 0xD09BAA9EB7148E58;

    float mfCompletedTiers;
    float mfMissionIndex;
    cTkEqualityEnum Test;
    bool mbTakeTierFromSeasonData;
}
