#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/stats/gcstatstypes.meta.h>

class cGcMissionSequenceGatherForRefuel
{
    static unsigned long long muNameHash = 0x9FA5A1E5E026A5B3;
    static unsigned long long muTemplateHash = 0x12EF3E077583FC5B;

    cTkFixedString<128,char> macMessage;
    cGcStatsTypes TargetStat;
    int miAmount;
    cTkFixedString<128,char> macDebugText;
}
