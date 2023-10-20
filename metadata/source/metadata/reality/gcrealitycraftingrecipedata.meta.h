#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcrealitysubstancecraftingmix.meta.h>

class cGcRealityCraftingRecipeData
{
    static unsigned long long muNameHash = 0x5CEC8CD158852BFE;
    static unsigned long long muTemplateHash = 0x90B4295D3193C0CF;

    cTkFixedArray<cGcRealitySubstanceCraftingMix> maInputs;
    TkID<128> mOutputID;
}
