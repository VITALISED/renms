#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcCreatureGenerationDomainTable
{
    static unsigned long long muNameHash = 0xCE47B2B5ED8374E1;
    static unsigned long long muTemplateHash = 0x87BF5DF8DA96608C;

    TkID<128> mId;
    cTkDynamicArray<cGcCreatureGenerationDomainEntry> maTables;
    float mfChanceOfHemisphereLimit;
    int miMaxToHemisphereLimit;
}
