#pragma once
#include <metadata/metadata_common.h>

class cGcPlanetInfo
{
    static unsigned long long muNameHash = 0x458D53EF402BA3C9;
    static unsigned long long muTemplateHash = 0x98F6CCB88342CA8;

    cTkFixedString<128,char> macPlanetDescription;
    cTkFixedString<128,char> macPlanetType;
    cTkFixedString<128,char> macWeather;
    cTkFixedString<128,char> macResources;
    cTkFixedString<128,char> macFlora;
    cTkFixedString<128,char> macFauna;
    cTkFixedString<128,char> macSentinels;
    bool mbIsWeatherExtreme;
    bool mbAreSentinelsExtreme;
    bool mbAreSentinelsModerate;
}
