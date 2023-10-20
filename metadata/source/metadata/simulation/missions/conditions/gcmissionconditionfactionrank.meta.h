#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/missions/types/gcmissionfaction.meta.h>

class cGcMissionConditionFactionRank
{
    static unsigned long long muNameHash = 0x986E86EA3EB2C57C;
    static unsigned long long muTemplateHash = 0xD9864A17CE548A7F;

    cGcMissionFaction Faction;
    bool mbUseSystemRace;
    int miRank;
}
