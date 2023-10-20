#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/player/gcplayerhazardtype.meta.h>

class cGcMissionConditionWeather
{
    static unsigned long long muNameHash = 0x9EACE51885CC7760;
    static unsigned long long muTemplateHash = 0xFA0C587EC17860FF;

    bool mbIsExtreme;
    cGcPlayerHazardType WeatherRequirement;
    bool mbStormActive;
    bool mbIgnoreStormIfInShip;
    bool mbAllowNonHazardExtremeIfNoStorms;
}
