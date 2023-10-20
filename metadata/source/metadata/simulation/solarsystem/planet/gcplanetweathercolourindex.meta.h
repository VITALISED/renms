#pragma once
#include <metadata/metadata_common.h>
enum eWeatherColourSet
{
    EWeatherColourSet_Common = 0,
    EWeatherColourSet_Rare = 1,
}

class cGcPlanetWeatherColourIndex
{
    static unsigned long long muNameHash = 0x8F4800F7EA8399A7;
    static unsigned long long muTemplateHash = 0x8B954AFB7658126B;

    eWeatherColourSet WeatherColourSet;
    int miIndex;
}
