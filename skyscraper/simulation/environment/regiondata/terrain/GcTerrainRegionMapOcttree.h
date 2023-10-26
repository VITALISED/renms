#pragma once

#include <skyscraper.h>
#include <simulation/environment/regiondata/terrain/GcRegionTerrain.h>

SKYSCRAPER_BEGIN

class cGcTerrainRegionMapOcttree
{
    struct sTableEntry
    {
        unsigned __int16 muFirstNode : 10;
        unsigned __int16 muNumNodes : 6;
    };

    struct sNode
    {
        cGcRegionTerrain *mpRegion;
    };

    struct sNodePos
    {
        unsigned __int16 muX;
        unsigned __int16 muY;
        unsigned __int16 muZ;
    };

    cGcTerrainRegionMapOcttree::sTableEntry maRootTable[2048];
    unsigned __int16 mauRootNodeIndices[1024];
    unsigned __int16 mauRootNodeHashes[10000];
    cGcTerrainRegionMapOcttree::sNode maNodes[10000];
    cGcTerrainRegionMapOcttree::sNodePos maPositions[10000];
    unsigned __int8 mauDepths[10000];
    unsigned __int16 mauParents[10000];
    unsigned __int16 mauChildren[10000];
    unsigned __int16 muNumNodes;
    unsigned __int16 muNumRootNodes;
    unsigned __int16 muNumLODs;
    unsigned __int16 muRootMask;
    long double mfMapScale;
    long double mfMapOffset;
    bool mbAddingRoots;
};

SKYSCRAPER_END