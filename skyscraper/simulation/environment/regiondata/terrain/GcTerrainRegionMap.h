#pragma once

#include <skyscraper.h>
#include <atomic>
#include <simulation/environment/regiondata/terrain/GcRegionTerrain.h>
#include <simulation/environment/regiondata/terrain/GcTerrainRegionMapOcttree.h>
#include <simulation/solarsystem/planet/GcPlanet.h>
#include <simulation/environment/regiondecorators/GcRegionDecoratorObjects.h>
#include <simulation/environment/regiondecorators/GcRegionDecoratorBuildings.h>
#include <toolkit/utilities/containers/TkListNodeStandalone.h>
#include <metadata/toolkit/voxel/generator/tkvoxelgeneratordata.meta.h>
#include <metadata/source/simulation/solarsystem/planet/gcspawndensity.meta.h>
#include <metadata/source/simulation/solarsystem/planet/gcplanetdata.meta.h>

SKYSCRAPER_BEGIN

class cGcTerrainRegionMap : public cTkRegionMapBase
{
    class cGcFoliageNodeData
    {
        cGcFadeNodeInstance mFadeMain;
        cGcFadeNodeInstance mFadeImposter;
        cGcPlanetObjectSpawnData *mpObject;
        cGcSpawnDensity *mpSpawnDensity;
        cTkMatrix34 *mpTransforms;
        cGcRegionDecoratorObjects::sFoliageNodePhysics mPhysics;
        TkHandle mNode;
        int miNumObjects;
        eTileType meTileType;
    };
    
    class cTkRegionStub
    {
        cTkVector3 mPosition;
        cTkVector3 mParentPosition;
        cGcRegionTerrain *mpRegion;
        bool mbActive;
        unsigned int muFastTreeIdx;
        unsigned int muParentFastTreeIdx;
    };

    struct AreChildrenRenderableJob
    {
        cGcTerrainRegionMap *mpRegionMap;
        int miLod;
        int miStartIndex;
        int miEndIndex;
        unsigned __int8 *maiOutResults;
        std::atomic<int> mComplete;
        bool mbKicked;
    };

    struct AreSiblingsRenderableJob
    {
        cGcTerrainRegionMap *mpRegionMap;
        int miLod;
        int miStartIndex;
        int miEndIndex;
        int miFurthestActiveLod;
        unsigned __int8 *maiOutResults;
        std::atomic<int> mComplete;
        bool mbKicked;
    };
    
    int miBorderRegions;
    int miOctreeDiameter;
    int miCentrePosX;
    int miCentrePosY;
    int miCentrePosZ;
    cTkVector3 mExactCentre;
    float mfCachedRadius;
    int miMinDistance;
    int miTotalSize;
    bool mbRegionListDirty;
    int *miNumGeneratorCallsPerFrame;
    int *miNumPolygoniseCallsPerFrame;
    int *miNumPostPolygoniseCallsPerFrame;
    std::array<std::array<cGcRegionTerrain *,1500>, 6> mapRegionPools;
    std::array<std::array<cGcTerrainRegionMap::cTkRegionStub,1500>, 6> maPrevStubs;
    cTkBitArray<unsigned __int64, 9000> maActiveRegions;
    TkHandle mRootNode;
    cGcTerrainRegionMapOcttree mFastRegionTree;
    cTkVoxelGeneratorData *mpGeneratorData;
    cGcPlanetBuildingData *mpBuildingData;
    cTkMatrix34 mMatrix;
    cTkVector3 mToCamera;
    std::array<TkHandle,6> maLODGroups;
    std::array<bool,6> mabIsLodVisible;
    std::array<bool,6> mabIsLodAABBVisible;
    std::array<bool,6> mabIsLodActive;
    std::array<int,6> maiNumRegions;
    std::array<void *,6> mapRegionArrays;
    std::array<int,6> maiLodOrder;
    std::array<int,6> maiNumVoxelsX;
    std::array<int,6> maiNumVoxelsY;
    std::array<int,6> maiNumVoxelsZ;
    std::array<cGcTerrainRegionMap::AreChildrenRenderableJob,6> mChildrenRenderableJobs;
    std::array<cGcTerrainRegionMap::AreSiblingsRenderableJob,6> mSiblingsRenderableJobs;
    cTkListNode<cGcRegionDecoratorObjects *> mObjectsUpgradeList;
    cTkListNode<cGcRegionDecoratorObjects *> mRigidBodyRefreshList;
    cTkListNode<cGcRegionDecoratorBuildings *> mBuildingsUpgradeList;
    bool mbHide;
    cTkFixedString<64,char> mName;
    int miRegionGeneratesInFlight;
    int miRegionStreamsMapped;
    int miRegionsWaitingToPostPolygonise;
    int miRegionsWaitingToPopulate;
    int miRegionsPostPolygonisedThisFrame;
    int miRegionsPopulatedThisFrame;
    int miRegionBuildsInFlight;
    long double mfTimeSpentPostPolygonisingThisFrame;
    long double mfTimeSpentPopulatingThisFrame;
};

SKYSCRAPER_END