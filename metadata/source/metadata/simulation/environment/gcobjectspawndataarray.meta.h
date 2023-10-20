#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cGcObjectSpawnDataArray
{
    static unsigned long long muNameHash = 0x3AAEFA9CCB9353C1;
    static unsigned long long muTemplateHash = 0x501E9D30483F120B;

    cGcTerrainTileType TileType;
    int miMaxObjectsToSpawn;
    cTkDynamicArray<cGcObjectSpawnData> maObjects;
}