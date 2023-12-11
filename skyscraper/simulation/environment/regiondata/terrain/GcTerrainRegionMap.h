/**
 * @file GcTerrainRegionMap.h
 * @author VITALISED & Contributors
 * @since 2023-12-11
 *
 * Copyright (C) 2023  VITALISED & Contributors
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include <skyscraper.h>

#include <simulation/environment/regiondata/terrain/GcTerrainRegionMapOcttree.h>
#include <simulation/environment/regiondecorators/GcRegionDecoratorBuildings.h>
#include <simulation/environment/regiondecorators/GcRegionDecoratorObjects.h>
#include <toolkit/utilities/containers/TkBitArray.h>
#include <toolkit/utilities/containers/TkListNodeStandalone.h>
#include <toolkit/voxel/manager/TkRegionMap.h>

#include <simulation/environment/gcplanetbuildingdata.meta.h>

SKYSCRAPER_BEGIN

class cGcRegionTerrain;

class cGcTerrainRegionMap : public cTkRegionMapBase
{
  public:
    struct cTkRegionStub
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
        uint8_t *maiOutResults;
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
        uint8_t *maiOutResults;
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
    std::array<std::array<cGcRegionTerrain *, 1500>, 6> mapRegionPools;
    std::array<std::array<cGcTerrainRegionMap::cTkRegionStub, 1500>, 6> maPrevStubs;
    cTkBitArray<uint64_t, true, 9000> maActiveRegions;
    TkHandle mRootNode;
    cGcTerrainRegionMapOcttree mFastRegionTree;
    cTkVoxelGeneratorData *mpGeneratorData;
    cGcPlanetBuildingData *mpBuildingData;
    cTkMatrix34 mMatrix;
    cTkVector3 mToCamera;
    std::array<TkHandle, 6> maLODGroups;
    std::array<bool, 6> mabIsLodVisible;
    std::array<bool, 6> mabIsLodAABBVisible;
    std::array<bool, 6> mabIsLodActive;
    std::array<int, 6> maiNumRegions;
    std::array<void *, 6> mapRegionArrays;
    std::array<int, 6> maiLodOrder;
    std::array<int, 6> maiNumVoxelsX;
    std::array<int, 6> maiNumVoxelsY;
    std::array<int, 6> maiNumVoxelsZ;
    std::array<cGcTerrainRegionMap::AreChildrenRenderableJob, 6> mChildrenRenderableJobs;
    std::array<cGcTerrainRegionMap::AreSiblingsRenderableJob, 6> mSiblingsRenderableJobs;
    cTkListNode<cGcRegionDecoratorObjects *> mObjectsUpgradeList;
    cTkListNode<cGcRegionDecoratorObjects *> mRigidBodyRefreshList;
    cTkListNode<cGcRegionDecoratorBuildings *> mBuildingsUpgradeList;
    bool mbHide;
    cTkFixedString<64, char> mName;
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