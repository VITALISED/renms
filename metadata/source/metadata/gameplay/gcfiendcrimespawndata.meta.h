#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcFiendCrimeSpawnData
{
    static unsigned long long muNameHash = 0x9F76738BACABEAD2;
    static unsigned long long muTemplateHash = 0xDEB0FEF9EC99F1EC;

    cGcCreatureTypes Type;
    float mfMinDist;
    float mfMaxDist;
    cTkFixedArray<int> maMinNum;
    cTkFixedArray<int> maMaxNum;
}
