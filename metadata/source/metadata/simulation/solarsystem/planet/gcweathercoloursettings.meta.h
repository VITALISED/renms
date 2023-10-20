#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/solarsystem/planet/gcweathercoloursettinglist.meta.h>

class cGcWeatherColourSettings
{
    static unsigned long long muNameHash = 0x156BFFBB5A2228FA;
    static unsigned long long muTemplateHash = 0x49916E75AC6E9D46;

    cGcWeatherColourSettingList GenericSettings;
    cTkFixedArray<cGcWeatherColourSettingList> maPerBiomeSettings;
}
