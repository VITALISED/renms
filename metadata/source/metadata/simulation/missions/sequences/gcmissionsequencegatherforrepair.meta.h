#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/stats/gcstatstypes.meta.h>

class cGcMissionSequenceGatherForRepair
{
    static unsigned long long muNameHash = 0x535215E1DEB68BB2;
    static unsigned long long muTemplateHash = 0x53FB642C980F1492;

    cTkFixedString<128,char> macMessage;
    cGcStatsTypes TargetStat;
    TkID<128> mGatherResource;
    cTkFixedString<128,char> macDebugText;
}
