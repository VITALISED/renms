#pragma once
#include <metadata/metadata_common.h>
#include <metadata/voxel/generator/tknoiseflattenpoint.meta.h>

class cTkVoxelGeneratorRegionData
{
    static unsigned long long muNameHash = 0xA1EC10F083963380;
    static unsigned long long muTemplateHash = 0x18388706836A5878;

    float mfPlanetRadius;
    float mfVoronoiPointDivisions;
    int miVoronoiSectorSeed;
    int miVoronoiPointSeed;
    cTkDynamicArray<cTkNoiseFlattenPoint> maFlattenTerrainPoints;
    cTkDynamicArray<float> maFlattenTypeChances;
    int miWaypointIndex;
    int miLandingPadIndex;
    float mfAddShelterChance;
    cTkFixedArray<int> maShelterIndices;
    int miNumShelters;
}
