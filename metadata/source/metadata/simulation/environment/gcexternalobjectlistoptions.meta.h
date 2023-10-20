#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcExternalObjectListOptions
{
    static unsigned long long muNameHash = 0x51E8334202D1B952;
    static unsigned long long muTemplateHash = 0xB27A8358427627CA;

    TkID<128> mName;
    TkID<128> mResourceHint;
    TkID<128> mResourceHintIcon;
    float mfProbability;
    float mfSeasonalProbabilityOverride;
    cGcTerrainTileType TileType;
    bool mbAllowLimiting;
    bool mbChooseUsingLifeLevel;
    cTkDynamicArray<cTkFixedString<128,char>> maOptions;
}
