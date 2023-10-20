#pragma once
#include <metadata/metadata_common.h>
enum eGalaxyStarAnomaly
{
    EGalaxyStarAnomaly_None = 0,
    EGalaxyStarAnomaly_AtlasStation = 1,
    EGalaxyStarAnomaly_AtlasStationFinal = 2,
    EGalaxyStarAnomaly_BlackHole = 3,
    EGalaxyStarAnomaly_MiniStation = 4,
}

class cGcGalaxyStarAnomaly
{
    static unsigned long long muNameHash = 0x6488969F6CD933A4;
    static unsigned long long muTemplateHash = 0xC7BB011FDDE5C738;

    eGalaxyStarAnomaly GalaxyStarAnomaly;
}
