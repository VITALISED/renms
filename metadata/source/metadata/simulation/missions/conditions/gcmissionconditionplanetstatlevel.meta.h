#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcMissionConditionPlanetStatLevel
{
    static unsigned long long muNameHash = 0x5E041EB212BC9D8D;
    static unsigned long long muTemplateHash = 0xFEB8071F61919F1E;

    TkID<128> mStat;
    int miAmount;
    unsigned long long mui64SpecificUA;
    bool mbUseCurrentUA;
    bool mbCalculateUAFromSeasonData;
    bool mbCalculateUAFromMilestoneIndex;
    bool mbTakeAmountFromSeasonData;
    cTkEqualityEnum Test;
}
