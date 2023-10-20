#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/ecosystem/creatures/gccreaturetypes.meta.h>
#include <metadata/simulation/ecosystem/gccreatureroledescription.meta.h>
#include <metadata/simulation/ecosystem/creatures/gccreatureinfo.meta.h>
#include <metadata/simulation/environment/gcterraintiletype.meta.h>
#include <metadata/simulation/ecosystem/gccreaturediet.meta.h>
#include <metadata/simulation/ecosystem/gccreaturehemisphere.meta.h>

class cGcCreatureRoleData
{
    static unsigned long long muNameHash = 0x3330409D2B3F48C1;
    static unsigned long long muTemplateHash = 0x814F1020C18B16EE;

    cTkSeed mSeed;
    cGcCreatureTypes Type;
    TkID<128> mCreatureId;
    cGcCreatureRoleDescription Description;
    cGcCreatureInfo Info;
    cGcTerrainTileType TileType;
    cGcCreatureDiet Diet;
    float mfGroupsPerSquareKm;
    cGcCreatureHemiSphere HemiSphere;
    TkID<256> mFilter;
}
