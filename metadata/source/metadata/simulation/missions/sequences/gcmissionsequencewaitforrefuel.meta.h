#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcMissionSequenceWaitForRefuel
{
    static unsigned long long muNameHash = 0x25696B35BE341F6C;
    static unsigned long long muTemplateHash = 0x72332EFEE6E8C934;

    cTkFixedString<128,char> macMessage;
    cGcStatsTypes TargetStat;
    int miAmount;
    cTkFixedString<128,char> macDebugText;
}
