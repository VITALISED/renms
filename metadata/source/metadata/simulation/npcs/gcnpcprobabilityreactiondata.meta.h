#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/npcs/gcnpcraceprobabilitymodifierdata.meta.h>

class cGcNPCProbabilityReactionData
{
    static unsigned long long muNameHash = 0x260459086692280D;
    static unsigned long long muTemplateHash = 0xC871D35B9F8AAF33;

    TkID<128> mName;
    float mfProbability;
    cTkDynamicArray<cGcNPCRaceProbabilityModifierData> maRaceModifiers;
}
