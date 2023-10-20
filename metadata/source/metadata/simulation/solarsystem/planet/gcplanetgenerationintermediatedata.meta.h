#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>

class cGcPlanetGenerationIntermediateData
{
    static unsigned long long muNameHash = 0x166980043AF05C9E;
    static unsigned long long muTemplateHash = 0x115882CCFDCC17BA;

    cTkSeed mSeed;
    int miTerrainSettingIndex;
    cGcGalaxyStarTypes StarType;
    cGcPlanetClass Class;
    cGcPlanetSize Size;
    cGcCreatureRoleDataTable CreatureRoles;
    cGcTerrainControls Terrain;
    cGcBiomeType Biome;
    cGcBiomeSubType BiomeSubType;
    cTkFixedString<128,char> macTerrainFile;
    cTkFixedString<128,char> macCreatureLandFile;
    cTkFixedString<128,char> macCreatureCaveFile;
    cTkFixedString<128,char> macCreatureWaterFile;
    cTkFixedString<128,char> macCreatureExtraWaterFile;
    cTkFixedString<128,char> macCreatureAirFile;
    cTkFixedString<128,char> macCreatureRobotFile;
    cTkDynamicArray<cGcExternalObjectListOptions> maExternalObjectLists;
    cTkDynamicArray<int> maExternalObjectListIndices;
    bool mbPrime;
}
