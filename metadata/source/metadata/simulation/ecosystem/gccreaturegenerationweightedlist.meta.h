#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/ecosystem/gccreaturegenerationweightedlistdomainentry.meta.h>

class cGcCreatureGenerationWeightedList
{
    static unsigned long long muNameHash = 0xE51761B21603792C;
    static unsigned long long muTemplateHash = 0x4F1226E9514AC6E8;

    cTkDynamicArray<cGcCreatureGenerationWeightedListDomainEntry> maGround;
    cTkDynamicArray<cGcCreatureGenerationWeightedListDomainEntry> maAir;
    cTkDynamicArray<cGcCreatureGenerationWeightedListDomainEntry> maCave;
    cTkDynamicArray<cGcCreatureGenerationWeightedListDomainEntry> maWater;
}
