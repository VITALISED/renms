#pragma once
#include <metadata/metadata_common.h>

class cGcNPCProbabilityWordReactionData
{
    static unsigned long long muNameHash = 0xE83E88B1C1909A3F;
    static unsigned long long muTemplateHash = 0x5E3AFAEDE336DCCD;

    TkID<256> mNextInteraction;
    float mfProbability;
}
