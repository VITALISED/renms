#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcEcosystemCreatureData
{
    static unsigned long long muNameHash = 0x3DFA2A5571B31ADB;
    static unsigned long long muTemplateHash = 0x50342415C20360EF;

    TkID<128> mCreature;
    cGcTerrainTileType TileType;
    float mfMinHeight;
    float mfMaxHeight;
    float mfRarity;
}
