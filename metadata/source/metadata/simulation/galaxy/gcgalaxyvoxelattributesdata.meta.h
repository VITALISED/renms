#pragma once
#include <metadata/metadata_common.h>

class cGcGalaxyVoxelAttributesData
{
    static unsigned long long muNameHash = 0x967BB69D82846BE5;
    static unsigned long long muTemplateHash = 0xF2B85C926A79352B;

    bool mbInsideGoalGap;
    float mfUnitDistanceFromGoalEdge;
    float mfRegionColourValue;
    cTkVector2 mTransitPopulationDistanceRange;
    float mfTransitPopulationPerpDistance;
    int miGuideStarMinimumCount;
    int miGuideStarRenegadeCount;
    int miBlackholeCount;
    int miAtlasStationCount;
    cTkFixedArray<int> maBlackholeIndices;
    cTkFixedArray<int> maAtlasStationIndices;
}
