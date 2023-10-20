#pragma once
#include <metadata/metadata_common.h>
enum eWeather
{
    EWeather_Clear = 0,
    EWeather_Dust = 1,
    EWeather_Humid = 2,
    EWeather_Snow = 3,
    EWeather_Toxic = 4,
    EWeather_Scorched = 5,
    EWeather_Radioactive = 6,
    EWeather_RedWeather = 7,
    EWeather_GreenWeather = 8,
    EWeather_BlueWeather = 9,
    EWeather_Swamp = 10,
    EWeather_Lava = 11,
    EWeather_Bubble = 12,
    EWeather_Weird = 13,
    EWeather_Fire = 14,
    EWeather_ClearCold = 15,
}

class cGcWeatherOptions
{
    static unsigned long long muNameHash = 0xA2AEA53FED6497EC;
    static unsigned long long muTemplateHash = 0x60CDE501516F083F;

    eWeather Weather;
}
