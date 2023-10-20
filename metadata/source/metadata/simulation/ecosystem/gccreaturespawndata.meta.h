#pragma once
#include <metadata/metadata_common.h>
#include <metadata/utilities/data/gcresourceelement.meta.h>
#include <metadata/simulation/environment/gcterraintiletype.meta.h>
#include <metadata/simulation/ecosystem/creatures/gccreaturetypes.meta.h>
#include <metadata/simulation/ecosystem/gccreatureroles.meta.h>
#include <metadata/simulation/ecosystem/gccreaturehemisphere.meta.h>
#include <metadata/reality/gcrarity.meta.h>

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
