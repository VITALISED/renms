#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/npcs/gcnpcwordreactioncategory.meta.h>

class cGcNPCWordReactionTable
{
    static unsigned long long muNameHash = 0xB4578AF4AEBD0B11;
    static unsigned long long muTemplateHash = 0x9553C1912E7347CF;

    cTkFixedArray<cGcNPCWordReactionCategory> maRaces;
}
