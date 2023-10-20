#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/solarsystem/planet/gcplanetarymappingvalues.meta.h>

class cGcPlanetaryMappingTable
{
    static unsigned long long muNameHash = 0xB47263D5F2CB7D5D;
    static unsigned long long muTemplateHash = 0x7D5EA61AE5C87574;

    cTkFixedArray<cGcPlanetaryMappingValues> maMappingInfo;
}
