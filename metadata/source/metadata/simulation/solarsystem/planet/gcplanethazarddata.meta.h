#pragma once
#include <metadata/metadata_common.h>

class cGcPlanetHazardData
{
    static unsigned long long muNameHash = 0x3DB976BCF84F474B;
    static unsigned long long muTemplateHash = 0xF74DD90BA5596BD5;

    cTkFixedArray<float> maTemperature;
    cTkFixedArray<float> maToxicity;
    cTkFixedArray<float> maRadiation;
    cTkFixedArray<float> maLifeSupportDrain;
}
