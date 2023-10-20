#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcPlanetHeavyAirData
{
    static unsigned long long muNameHash = 0x2E1B1C402A21253;
    static unsigned long long muTemplateHash = 0x14D9F46D8E0CEDDB;

    cTkFixedString<128,char> macFilename;
    cTkFixedArray<cGcHeavyAirColourData> maColours;
}
