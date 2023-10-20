#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/npcs/gcnpcwordreactionlist.meta.h>

class cGcNPCWordReactionCategory
{
    static unsigned long long muNameHash = 0x68CB2B62199F1EFA;
    static unsigned long long muTemplateHash = 0xC4EEDF35BA1C202B;

    cTkFixedArray<cGcNPCWordReactionList> maCategories;
    cGcNPCWordReactionList Fallback;
}
