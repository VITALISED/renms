#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcModelExplosionRules
{
    static unsigned long long muNameHash = 0xD04C1E382833D93A;
    static unsigned long long muTemplateHash = 0x4251055E922DDCF4;

    cTkDynamicArray<cGcModelExplosionRule> maRules;
    cTkFixedArray<bool> maUseRules;
    cTkFixedArray<float> maShipSalvageDisplayScales;
}
