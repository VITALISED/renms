#pragma once
#include <metadata/metadata_common.h>
#include <metadata/tkequalityenum.meta.h>

class cGcMissionConditionStatDiff
{
    static unsigned long long muNameHash = 0x4315517EE11B4860;
    static unsigned long long muTemplateHash = 0xE7FB498200797448;

    TkID<128> mCurrentStat;
    TkID<128> mTargetStat;
    int miAmountPastTarget;
    cTkEqualityEnum Test;
}
