#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/ecosystem/gccreaturegenerationdensity.meta.h>

class cGcCreatureGenerationDomainEntry
{
    static unsigned long long muNameHash = 0x79E2609CF7F155CE;
    static unsigned long long muTemplateHash = 0x6F71AA2B77D5938C;

    cGcCreatureGenerationDensity DensityModifier;
    cTkFixedString<128,char> macFile;
}
