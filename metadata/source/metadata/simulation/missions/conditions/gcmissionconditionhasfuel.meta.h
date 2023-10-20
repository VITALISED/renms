#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/stats/gcstatstypes.meta.h>

class cGcMissionConditionHasFuel
{
    static unsigned long long muNameHash = 0x2A8282CD4FA96596;
    static unsigned long long muTemplateHash = 0x2FCAD48C117FDB2F;

    cGcStatsTypes TargetStat;
    int miAmount;
    TkID<128> mSpecificTechID;
    bool mbFormatTextAsPercentage;
}
