#pragma once
#include <metadata/metadata_common.h>
enum eTileType
{
    ETileType_Air = 0,
    ETileType_Base = 1,
    ETileType_Rock = 2,
    ETileType_Mountain = 3,
    ETileType_Underwater = 4,
    ETileType_Cave = 5,
    ETileType_Dirt = 6,
    ETileType_Liquid = 7,
    ETileType_Substance = 8,
}

class cGcTerrainTileType
{
    static unsigned long long muNameHash = 0x6247F06C43E3ADDD;
    static unsigned long long muTemplateHash = 0x75811DA9180574C6;

    eTileType TileType;
}
