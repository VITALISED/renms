#pragma once
#include <metadata/metadata_common.h>
#include <metadata/tkequalityenum.meta.h>

class cGcMissionConditionStatLevel
{
    static unsigned long long muNameHash = 0xA56864A865FEBE6D;
    static unsigned long long muTemplateHash = 0x8AD6D9760D21ED40;

    TkID<128> mStat;
    TkID<128> mStatGroup;
    int miLevel;
    int miLevelledStatRank;
    bool mbTakeLevelFromSeasonData;
    bool mbForceIgnoreLevelledStat;
    TkID<128> mCompareStat;
    int miDisplayMilestoneNumber;
    cTkEqualityEnum Test;
}
