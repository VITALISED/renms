#pragma once
#include <metadata/metadata_common.h>
enum eSentinelLevel
{
    ESentinelLevel_Low = 0,
    ESentinelLevel_Default = 1,
    ESentinelLevel_Aggressive = 2,
}

class cGcPlanetSentinelData
{
    static unsigned long long muNameHash = 0x1EB5C4AE3BDB484E;
    static unsigned long long muTemplateHash = 0x6AB59E33F960A69F;

    eSentinelLevel SentinelLevel;
    int miMaxActiveDrones;
}
