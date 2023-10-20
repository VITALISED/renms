#pragma once
#include <metadata/metadata_common.h>
enum eWonderPlanetCategory
{
    EWonderPlanetCategory_TemperatureMax = 0,
    EWonderPlanetCategory_TemperatureMin = 1,
    EWonderPlanetCategory_ToxicityMax = 2,
    EWonderPlanetCategory_RadiationMax = 3,
    EWonderPlanetCategory_AnomalyMax = 4,
    EWonderPlanetCategory_RadiusMax = 5,
    EWonderPlanetCategory_RadiusMin = 6,
    EWonderPlanetCategory_AltitudeReachedMax = 7,
    EWonderPlanetCategory_AltitudeReachedMin = 8,
    EWonderPlanetCategory_PerfectionMax = 9,
    EWonderPlanetCategory_PerfectionMin = 10,
}

class cGcWonderPlanetCategory
{
    static unsigned long long muNameHash = 0x1496B0F5A0E7C1DE;
    static unsigned long long muTemplateHash = 0x974FA15CCF1DC507;

    eWonderPlanetCategory WonderPlanetCategory;
}
