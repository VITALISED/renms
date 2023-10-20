#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>

class cGcPlanetBuildingData
{
    static unsigned long long muNameHash = 0xF6213EDD899A8CAE;
    static unsigned long long muTemplateHash = 0x9E12FCC020E66CD3;

    cTkDynamicArray<cGcBuildingSpawnSlot> maBuildingSlots;
    cTkDynamicArray<cGcBuildingSpawnData> maBuildings;
    cTkDynamicArray<cGcBuildingOverrideData> maOverrideBuildings;
    float mfSpacing;
    float mfPlanetRadius;
    float mfVoronoiPointDivisions;
    int miVoronoiSectorSeed;
    int miVoronoiPointSeed;
    bool mbInitialBuildingsPlaced;
    bool mbIsPrime;
}
