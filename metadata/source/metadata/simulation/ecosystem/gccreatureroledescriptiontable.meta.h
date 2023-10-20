#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>

class cGcCreatureRoleDescriptionTable
{
    static unsigned long long muNameHash = 0xBCFEFAC14ECD961B;
    static unsigned long long muTemplateHash = 0x3BCE966DA1F26340;

    cTkDynamicArray<cGcCreatureRoleDescription> maRoleDescription;
    float mfMinScaleVariance;
    float mfMaxScaleVariance;
    cGcTerrainTileType TileType;
    cGcPlanetLife LifeLevel;
}
