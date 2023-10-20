#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>

class cGcCreatureSpawnData
{
    static unsigned long long muNameHash = 0x17AC2C984675F276;
    static unsigned long long muTemplateHash = 0xD643FA7CFC3A8317;

    cGcResourceElement Resource;
    cGcResourceElement FemaleResource;
    cGcResourceElement ExtraResource;
    cGcTerrainTileType TileType;
    bool mbSwapPrimaryForSecondaryColour;
    bool mbSwapPrimaryForRandomColour;
    float mfMinScale;
    float mfMaxScale;
    TkID<128> mCreatureID;
    cGcCreatureTypes CreatureType;
    cGcCreatureRoles CreatureRole;
    TkID<256> mFilter;
    int miCreatureMinGroupSize;
    int miCreatureMaxGroupSize;
    float mfCreatureGroupsPerSquareKm;
    cGcCreatureHemiSphere HemiSphere;
    float mfCreatureSpawnDistance;
    float mfCreatureDespawnDistance;
    float mfCreatureActiveInDayChance;
    float mfCreatureActiveInNightChance;
    cGcRarity Rarity;
    bool mbAllowFur;
    bool mbHerd;
    int miRoleDataIndex;
}
