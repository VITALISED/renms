#pragma once

#include <skyscraper.h>
#include <simulation/environment/regiondata/terrain/GcRegionTerrainVeryFar.h>

SKYSCRAPER_BEGIN

class cGcRegionDecoratorBuildings
{
    struct sAddBuildingParams
    {
        cTkVector3 mInputPosition;
        cTkVector3 mCenterPosition;
        cTkSeed mSectorID;
        cTkVector3 mpaPositions[41];
        cTkVector3 mpaDirections[41];
        float mpafDistances[41];
        cTkSeed mpaSeeds[41];
        int mpaiBuildingIndices[41];
        bool mbaIsInitialSettlementBuilding[41];
    };

    cGcRegionTerrainFar *mpRegion;
    cTkStackVector<cGcBuilding *> mBuildings;
    cTkStackVector<cGcRegionDecoratorBuildings::sAddBuildingParams> maGeneratedBuildingParams;
    cTkStackVector<cGcWFCBuildingState *> mWFCStates;
    TkHandle mGroupNode;
    TkHandle mCrashedShipGroupNode;
    cGcPlanet *mpPlanet;
    cGcRegionDecoratorBuildings::eBuildingUpgradeState meCurrentUpgradeState;
    bool mbBuildingsSpawned;
    TkIterationState<2> mUpgradeIterationState;
    cTkListNode<cGcRegionDecoratorBuildings *> mUpgradeNode;
    std::vector<sRegionEdit> mBuildingTerrainEdits;
    std::vector<cGcRegionDecoratorBuildings::cGcUpgradeMarker> maUpgradeMarkers;
    bool mbRecordSpawnFails;
};

SKYSCRAPER_END