#pragma once
#include <metadata/metadata_common.h>
enum eSentinelType
{
    ESentinelType_PatrolDrone = 0,
    ESentinelType_CombatDrone = 1,
    ESentinelType_MedicDrone = 2,
    ESentinelType_SummonerDrone = 3,
    ESentinelType_CorruptedDrone = 4,
    ESentinelType_Quad = 5,
    ESentinelType_Mech = 6,
    ESentinelType_Walker = 7,
    ESentinelType_FriendlyDrone = 8,
}

class cGcSentinelTypes
{
    static unsigned long long muNameHash = 0x4C87DB0C59434DB3;
    static unsigned long long muTemplateHash = 0x3F0158EC0BC49377;

    eSentinelType SentinelType;
}
