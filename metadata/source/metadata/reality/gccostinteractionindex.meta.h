#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/components/gameplay/gcinteractiontype.meta.h>
#include <metadata/reality/gcalienrace.meta.h>

class cGcCostInteractionIndex
{
    static unsigned long long muNameHash = 0x8005E8FA6CB39C35;
    static unsigned long long muTemplateHash = 0x238FBBF0FEA04F51;

    cGcInteractionType InteractionType;
    cGcAlienRace Race;
    int miIndex;
    bool mbAffordIfGreaterThanIndex;
    TkID<256> mCantAffordLocID;
}
