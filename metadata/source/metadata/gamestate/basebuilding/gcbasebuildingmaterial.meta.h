#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcBaseBuildingMaterial
{
    static unsigned long long muNameHash = 0x83E238320B2BEE42;
    static unsigned long long muTemplateHash = 0x2FF161ED46008665;

    cTkTextureResource Icon;
    cTkTextureResource SwatchImage;
    TkID<256> mLocName;
    TkID<256> mId;
    int miMaterialIndex;
}
