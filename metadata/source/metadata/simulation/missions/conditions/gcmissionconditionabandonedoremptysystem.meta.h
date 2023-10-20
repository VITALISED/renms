#pragma once
#include <metadata/metadata_common.h>
enum eMissionSystemType
{
    EMissionSystemType_Either = 0,
    EMissionSystemType_Empty = 1,
    EMissionSystemType_Abandoned = 2,
}

class cGcMissionConditionAbandonedOrEmptySystem
{
    static unsigned long long muNameHash = 0x651218B208D538A0;
    static unsigned long long muTemplateHash = 0x1EB28DC3AE2177C7;

    eMissionSystemType MissionSystemType;
}
