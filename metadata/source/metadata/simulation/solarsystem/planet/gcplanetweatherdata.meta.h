#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/environment/weather/gcweatheroptions.meta.h>
#include <metadata/simulation/solarsystem/planet/gcplanetheavyairdata.meta.h>
enum eWeatherIntensity
{
    EWeatherIntensity_Default = 0,
    EWeatherIntensity_Extreme = 1,
}
enum eStormFrequency
{
    EStormFrequency_None = 0,
    EStormFrequency_Low = 1,
    EStormFrequency_High = 2,
}
#include <metadata/graphics/gcscreenfilters.meta.h>
#include <metadata/simulation/solarsystem/planet/gcrainbowtype.meta.h>

class cGcPlanetWeatherData
{
    static unsigned long long muNameHash = 0xEBF08BE1E3CAE3AC;
    static unsigned long long muTemplateHash = 0x69F3C1EFE29BC64E;

    cGcWeatherOptions WeatherType;
    cGcPlanetHeavyAirData HeavyAir;
    eWeatherIntensity WeatherIntensity;
    eStormFrequency StormFrequency;
    eAtmosphereType AtmosphereType;
    int miDayColourIndex;
    int miDuskColourIndex;
    cGcScreenFilters ScreenFilter;
    cGcScreenFilters StormScreenFilter;
    cGcRainbowType RainbowType;
    int miNightColourIndex;
}
