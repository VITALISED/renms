#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcMissionSequenceWaitForRepair
{
    static unsigned long long muNameHash = 0x79652C883CA60AE;
    static unsigned long long muTemplateHash = 0xD8AFC2D511BF5588;

    cTkFixedString<128,char> macMessage;
    cGcStatsTypes TargetStat;
    cTkFixedString<128,char> macDebugText;
}
