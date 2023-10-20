#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/environment/weather/gcweathereffect.meta.h>

class cGcWeatherEffectTable
{
    static unsigned long long muNameHash = 0x6AE3CB3B6A5A155D;
    static unsigned long long muTemplateHash = 0xB21D1EF7FE2332D0;

    cTkDynamicArray<cGcWeatherEffect> maEffects;
}
