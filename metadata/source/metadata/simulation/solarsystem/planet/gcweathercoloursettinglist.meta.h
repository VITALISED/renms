#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/solarsystem/planet/gcplanetweathercolourdata.meta.h>

class cGcWeatherColourSettingList
{
    static unsigned long long muNameHash = 0xB5D0CD9B9ED4C2E8;
    static unsigned long long muTemplateHash = 0xDA91BB5D56A58448;

    cTkDynamicArray<cGcPlanetWeatherColourData> maSettings;
}
