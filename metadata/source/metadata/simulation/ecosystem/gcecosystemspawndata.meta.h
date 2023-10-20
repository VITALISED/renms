#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcEcosystemSpawnData
{
    static unsigned long long muNameHash = 0xB2F82AE85A5CD5EE;
    static unsigned long long muTemplateHash = 0x7B710B6ECC0C1CD5;

    cTkDynamicArray<cGcEcosystemCreatureData> maCreatures;
    float mfCreatureMinNoise;
    float mfCreatureMaxNoise;
}
