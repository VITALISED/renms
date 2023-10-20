#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/ecosystem/gccreaturegenerationdomaintable.meta.h>

class cGcCreatureGenerationArchetypes
{
    static unsigned long long muNameHash = 0xCFE07CC2C3280EC;
    static unsigned long long muTemplateHash = 0x696350FCE04E777F;

    cTkDynamicArray<cGcCreatureGenerationDomainTable> maGroundArchetypes;
    cTkDynamicArray<cGcCreatureGenerationDomainTable> maAirArchetypes;
    cTkDynamicArray<cGcCreatureGenerationDomainTable> maWaterArchetypes;
    cTkDynamicArray<cGcCreatureGenerationDomainTable> maCaveArchetypes;
}
