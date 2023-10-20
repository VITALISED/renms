#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcWeatherTable
{
    static unsigned long long muNameHash = 0x4452780AB55C81D6;
    static unsigned long long muTemplateHash = 0xE82BC2FFD780DC01;

    cTkFixedArray<cTkFixedString<128,char>> maTable;
    cTkFixedArray<cGcHazardValues> maDefaultTemperature;
    cTkFixedArray<cGcHazardValues> maDefaultToxicity;
    cTkFixedArray<cGcHazardValues> maDefaultRadiation;
}
