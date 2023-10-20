#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/missions/types/gcmissionfaction.meta.h>

class cGcRewardFactionStanding
{
    static unsigned long long muNameHash = 0x8B79DF642602985A;
    static unsigned long long muTemplateHash = 0x257E7127D990C3BB;

    cGcMissionFaction Faction;
    int miAmountMin;
    int miAmountMax;
    bool mbSetToMinBeforeAdd;
}
