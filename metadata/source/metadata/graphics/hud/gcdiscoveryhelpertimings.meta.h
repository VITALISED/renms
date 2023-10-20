#pragma once
#include <metadata/metadata_common.h>

class cGcDiscoveryHelperTimings
{
    static unsigned long long muNameHash = 0xD14651666CB8A6EB;
    static unsigned long long muTemplateHash = 0xF3469FD77B8FF885;

    float mfDiscoverPlanetTotalTime;
    float mfDiscoverPlanetMessageWait;
    float mfDiscoverPlanetMessageTime;
}
