#pragma once
#include <metadata/metadata_common.h>

class cGcPlanetSectionData
{
    static unsigned long long muNameHash = 0x408CCAADC93DEEFE;
    static unsigned long long muTemplateHash = 0x4BFC6055460243D3;

    unsigned long long mui64DiscovererUID;
    cTkFixedArray<unsigned char> maDiscovererPlatform;
    bool mbDiscoveredState;
}
