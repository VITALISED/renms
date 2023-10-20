#pragma once
#include <metadata/metadata_common.h>
#include <metadata/utilities/data/tkheavyairdata.meta.h>

class cTkHeavyAirCollection
{
    static unsigned long long muNameHash = 0x67009714D686CB9F;
    static unsigned long long muTemplateHash = 0xDF7E1282F31CADFE;

    cTkDynamicArray<cTkHeavyAirData> maHeavyAirSystems;
}
