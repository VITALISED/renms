#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/solarsystem/planet/gcheavyairsettingvalues.meta.h>

class cGcHeavyAirSetting
{
    static unsigned long long muNameHash = 0x6E90E2A796E798F4;
    static unsigned long long muTemplateHash = 0x87D38F494FB0DD9B;

    cTkFixedArray<cGcHeavyAirSettingValues> maSettings;
}
