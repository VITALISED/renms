#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/environment/gcfogproperties.meta.h>
#include <metadata/simulation/environment/weather/gcweathercolourmodifiers.meta.h>
#include <metadata/simulation/environment/gcstormproperties.meta.h>
#include <metadata/simulation/environment/weather/gchazardvalues.meta.h>
#include <metadata/graphics/gcscreenfilters.meta.h>
#include <metadata/simulation/environment/gcskyproperties.meta.h>
#include <metadata/simulation/environment/gclightshaftproperties.meta.h>

class cGcWeatherProperties
{
    static unsigned long long muNameHash = 0xD216CE8E772352C;
    static unsigned long long muTemplateHash = 0xBDD9439B9B595EF6;

    TkID<128> mName;
    bool mbUseWeatherFog;
    cGcFogProperties Fog;
    cGcFogProperties FlightFog;
    cGcFogProperties StormFog;
    cGcFogProperties ExtremeFog;
    cGcWeatherColourModifiers ExtremeColourModifiers;
    cTkFixedArray<float> maRainbowChance;
    cTkDynamicArray<cGcStormProperties> maStorms;
    cTkDynamicArray<cTkFixedString<128,char>> maHeavyAir;
    float mfLowStormsChance;
    float mfHighStormsChance;
    float mfExtremeWeatherChance;
    bool mbOverrideTemperature;
    cTkFixedArray<cGcHazardValues> maTemperature;
    bool mbOverrideToxicity;
    cTkFixedArray<cGcHazardValues> maToxicity;
    bool mbOverrideRadiation;
    cTkFixedArray<cGcHazardValues> maRadiation;
    cTkFixedArray<cGcHazardValues> maLifeSupportDrain;
    cTkDynamicArray<cGcScreenFilters> maStormFilterOptions;
    bool mbUseWeatherSky;
    cGcSkyProperties Sky;
    bool mbUseLightShaftProperties;
    cGcLightShaftProperties LightShaftProperties;
    bool mbUseStormLightShaftProperties;
    cGcLightShaftProperties StormLightShaftProperties;
    cTkDynamicArray<TkID<128>> maWeatherEffectsIds;
    cTkDynamicArray<TkID<128>> maWeatherHazardsIds;
}
