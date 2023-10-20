#pragma once
#include <metadata/metadata_common.h>
enum eGridLayerTypes
{
    EGridLayerTypes_Small = 0,
    EGridLayerTypes_Large = 1,
    EGridLayerTypes_Resources_Heridium = 2,
    EGridLayerTypes_Resources_Iridium = 3,
    EGridLayerTypes_Resources_Copper = 4,
    EGridLayerTypes_Resources_Nickel = 5,
    EGridLayerTypes_Resources_Aluminium = 6,
    EGridLayerTypes_Resources_Gold = 7,
    EGridLayerTypes_Resources_Emeril = 8,
}

class cTkGridLayersEnum
{
    static unsigned long long muNameHash = 0xFEF6F10412C7B60;
    static unsigned long long muTemplateHash = 0xB9F17954D3E62F66;

    eGridLayerTypes GridLayerTypes;
}
