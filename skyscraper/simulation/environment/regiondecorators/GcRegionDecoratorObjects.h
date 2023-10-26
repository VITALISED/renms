#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

class cGcRegionTerrainVeryFar;

class cGcRegionDecoratorObjects
{
    struct sFoliageInstanceRigidBody
    {
        cTkMatrix34 mTransform;
        __int16 miCollisionIdx;
        __int16 miRigidBodyIdx;
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

    cGcRegionTerrainVeryFar *mpRegion;
    float mfSpawnDensity;
    std::vector<cGcRegionDecoratorObjects::cGcFoliageNodeData> mFoliageNodes;
    TkStrongType<int,TkStrongTypeIDs::TkResHandleID> mBillboardResource;
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
    cTkBitArray<unsigned __int64,1,128> muFNBit_HasObjects;
    cTkBitArray<unsigned __int64,1,128> muFNBit_HasPhysics;
    cTkBitArray<unsigned __int64,1,128> muFNBit_HasPlayerCollision;
    cTkBitArray<unsigned __int64,1,128> muFNBit_PhysicsActivated;
    cTkBitArray<unsigned __int64,1,128> muFNBit_PhysicsDirty;
    cGcRegionDecoratorObjects::eFoliageUpgradeState meCurrentUpgradeState;
    TkIterationState<2> mUpgradeIterationState;
    cGcRegionDecoratorObjects::FoliageUpgraderState mFoliageUpgraderState;
    cTkListNode<cGcRegionDecoratorObjects *> mUpgradeNode;
    cTkListNode<cGcRegionDecoratorObjects *> mRigidBodyRefreshNode;
    unsigned __int8 *mpTempAllocator;
    unsigned __int8 *mpTempAllocatorStart;
    unsigned __int8 *mpTempAllocatorEnd;
    cTkMatrix34 *mpAddTransformMatrices;
    int *mpAddTransformIndices;
    int miAddTransformMax;
    int miAddTransformCount;
    std::vector<cGcRegionDecoratorObjects::cGcUpgradeMarker> maUpgradeMarkers;
    std::vector<cGcRegionDecoratorObjects::SpawnFail> maFails;
    bool mbRecordSpawnFails;
};

SKYSCRAPER_END