#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/solarsystem/planet/gcplanetwatercolourdata.meta.h>

class cGcWaterColourSettingList
{
    static unsigned long long muNameHash = 0xB2E60FCA3C5550F9;
    static unsigned long long muTemplateHash = 0x393AEE313EAF1227;

    cTkDynamicArray<cGcPlanetWaterColourData> maSettings;
}
