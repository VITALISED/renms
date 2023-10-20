#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>

class cGcRegionHotspotsTable
{
    static unsigned long long muNameHash = 0x7F0D775900CDB2FD;
    static unsigned long long muTemplateHash = 0x1EEB6E34193A8D63;

    float mfRegionHotspotsPoleSpacing;
    float mfRegionHotspotsPerPoleMin;
    float mfRegionHotspotsPerPoleMax;
    float mfRegionHotspotsMinSameCategorySpacing;
    float mfRegionHotspotsMaxDifferentCategoryOverlap;
    cTkFixedArray<cGcRegionHotspotData> maRegionHotspots;
    cTkFixedArray<cGcRegionHotspotBiomeGases> maRegionHotspotBiomeGases;
    cTkDynamicArray<cGcRegionHotspotSubstance> maRegionHotspotSubstances;
}