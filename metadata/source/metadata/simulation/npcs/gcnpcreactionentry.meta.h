#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcNPCReactionEntry
{
    static unsigned long long muNameHash = 0x55C21F4B95AD18C8;
    static unsigned long long muTemplateHash = 0x8C9B8E280D8E2CF5;

    TkID<128> mEmote;
    float mfReactionChance;
    cTkDynamicArray<cGcNPCProbabilityReactionData> maAnimations;
}
