/**
 * @file GcRegionDecoratorObjects.h
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

#include <engine/extensions/shaders/TerrainGenShared.h>
#include <simulation/scenemanager/GcFadeNode.h>
#include <simulation/solarsystem/planet/GcPlanetCommon.h>
#include <toolkit/maths/geometry/TkAABB.h>
#include <toolkit/system/TkIterationState.h>
#include <toolkit/utilities/containers/TkBitArray.h>
#include <toolkit/utilities/containers/TkListNodeStandalone.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/voxel/manager/TkRegionHeightTest.h>

#include <simulation/solarsystem/planet/gcspawndensity.meta.h>

SKYSCRAPER_BEGIN

class cGcPlanet;
class cGcRegionTerrainVeryFar;
class cGcRegionDecoratorPhysics;

enum eSpawnGroup
{
    ESpawnGroup_DetailObjects,
    ESpawnGroup_Objects,
    ESpawnGroup_Landmarks,
    ESpawnGroup_DistantObjects,
    ESpawnGroup_NumTypes,
};

class cGcRegionDecoratorObjects
{
  public:
    enum eFoliageUpgradeState
    {
        EFoliageUpgradeState_None,
        EFoliageUpgradeState_NeedsUpgrade,
        EFoliageUpgradeState_Foliage_InProgress,
        EFoliageUpgradeState_Upgraded,
    };

    struct sFoliageInstanceRigidBody
    {
        cTkMatrix34 mTransform;
        int16_t miCollisionIdx;
        int16_t miRigidBodyIdx;
        bool mbCreated;
        bool mbRemoved;
        bool mbActivating;
    };

    struct sFoliageNodePhysics
    {
        cGcRegionDecoratorPhysics *mpPhysics;
        cGcRegionDecoratorObjects::sFoliageInstanceRigidBody *mpRigidBodies;
        TkHandle mCollisionNode;
    };

    class cGcFoliageNodeData
    {
      public:
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

    struct sComputeGetTrianglesResults
    {
        cTkRegionHeightResult *mpPositions;
        unsigned int *mpPositionSeeds;
        int miNumPositions;
        GPU::sGetTriangleCountOutput *mpTriangleCounts;
        unsigned int *mpuPositionToTriangleMap;
        unsigned int *mpuTotalPositionCount;
        GPU::sTerrainVertexUnpacked *mpUnpackedVerts;
        unsigned int muPositionBufferSize;
        unsigned int muPositionGenCounterAddress;
        unsigned int *mpuPositionGenIndirectDispatch;
    };

    struct sComputeAddResults
    {
        GPU::sObjectTypePriorityMap mPriorityMap;
        GPU::sObjectTypeInfo maTypeInfo[256];
        unsigned int *mpuBuildTypesPerPositionIndirectDispatch;
        unsigned int muBuildTypesPerPositionCounterAddress;
        unsigned int *mpuNumPositionEntries;
        GPU::sAddObjectPosIndex *mpTypesPerPositionBuffer;
        unsigned int muTypesPerPositionBufferSize;
        GPU::sSpawnObjectGlobalParams mSpawnGlobalParams;
        GPU::sSpawnObjectPerTypeParams *mpSpawnPerTypeParams;
        int *mpiSpawnResultStages;
        GPU::sSpawnObjectResult *mpSpawnResults;
        uint64_t *mpuFilterBits;
        unsigned int *mpuFilterIndirectDispatch;
    };

    struct FoliageUpgraderState
    {
        cTkVector3 mRayExtensionVector;
        cTkMatrix44 *mpaMatricesOrdered;
        cTkVector4 *mpaInterpolateFromVectorsOrdered;
        cTkVector3 *mpaCachedPositionsOrdered;
        int *mpaInstanceOrder;
        TkHandle mCollisionNode;
        TkHandle mParentNode;
    };

    cGcRegionTerrainVeryFar *mpRegion;
    float mfSpawnDensity;
    cTkVector<cGcRegionDecoratorObjects::cGcFoliageNodeData> mFoliageNodes;
    TkStrongType<int, TkStrongTypeIDs::TkResHandleID> mBillboardResource;
    int miNumObjectTypes;
    eSpawnGroup meSpawnGroup;
    TkHandle mGroupNode;
    cGcPlanet *mpPlanet;
    cTkVector3 mPlanetPosition;
    int miDistance;
    cTkAABB mRegionAabb;
    cGcRegionDecoratorObjects::sComputeGetTrianglesResults *mpComputeGetTrianglesResults;
    cGcRegionDecoratorObjects::sComputeAddResults *mpComputeAddResults;
    int miGlobalLimitObjectCount;
    int miGlobalLimitPhysicsObjectCount;
    cTkBitArray<uint64_t, true, 128> muFNBit_HasObjects;
    cTkBitArray<uint64_t, true, 128> muFNBit_HasPhysics;
    cTkBitArray<uint64_t, true, 128> muFNBit_HasPlayerCollision;
    cTkBitArray<uint64_t, true, 128> muFNBit_PhysicsActivated;
    cTkBitArray<uint64_t, true, 128> muFNBit_PhysicsDirty;
    cGcRegionDecoratorObjects::eFoliageUpgradeState meCurrentUpgradeState;
    TkIterationState<2> mUpgradeIterationState;
    cGcRegionDecoratorObjects::FoliageUpgraderState mFoliageUpgraderState;
    cTkListNode<cGcRegionDecoratorObjects *> mUpgradeNode;
    cTkListNode<cGcRegionDecoratorObjects *> mRigidBodyRefreshNode;
    uint8_t *mpTempAllocator;
    uint8_t *mpTempAllocatorStart;
    uint8_t *mpTempAllocatorEnd;
    cTkMatrix34 *mpAddTransformMatrices;
    int *mpAddTransformIndices;
    int miAddTransformMax;
    int miAddTransformCount;
};

SKYSCRAPER_END