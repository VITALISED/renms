/**
 * @file GcAsteroidManager.h
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

#include <simulation/solarsystem/asteroid/GcAsteroidGrids.h>
#include <simulation/solarsystem/asteroid/GcAsteroidPatternGenerator.h>
#include <toolkit/maths/geometry/TkPhysRelVec3.h>
#include <toolkit/maths/geometry/TkSphere.h>
#include <toolkit/simulation/physics/havok/TkCollision.h>
#include <toolkit/simulation/physics/havok/TkRigidBody.h>
#include <toolkit/utilities/containers/TkBitArray.h>
#include <toolkit/utilities/containers/TkClassPool.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <simulation/gcasteroidsystemgenerationdata.meta.h>
#include <simulation/solarsystem/gcsolarsystemdata.meta.h>
#include <toolkit/voxel/generator/tkvoxelgeneratordata.meta.h>

SKYSCRAPER_BEGIN

enum eAsteroidType
{
    EAsteroidType_None,
    EAsteroidType_Rare,
    EAsteroidType_Common,
    EAsteroidType_Large,
    EAsteroidType_Ring,
    EAsteroidType_Fuel,
    EAsteroidType_NumTypes,
};

class cGcInstancedPhysicsAsteroidGrid
{
  public:
    const int miSize;
    const int miDivideInstances;
    const int miNumPhysics;
    const int kiGridSize;
    const int kiMaxNumInstances;
    TkHandle mInstanceNode;
    TkHandle mCollisionNode;
    float mfVisibleDistanceSq;
    cTkBitArray<uint64_t, false, 0> mxValidity;
    cTkVector<short> maiInstanceGridIndex;
    cTkVector<cTkCollision> maCollisions;
    cTkVector<cTkRigidBody> maRigidBodies;
    cTkVector<int> maiTransformIndex;
    cTkVector<int> maiHitCounter;
    robin_hood::detail::Table<
        true, 80, cTkRigidBody const *, int, robin_hood::hash<cTkRigidBody const *, void>,
        std::equal_to<cTkRigidBody const *>>
        mBodyLookup;
    cTkSmartResHandle mResource;
    int miHealth;
    bool mbPhysicsDisabled;
    int miCurrentTransform;
    bool mbVertical;
    cTkClassPool<cTkSphere, 32> *mpInvalidAreas;
    cTkClassPool<cGcAsteroidRing, 32> *mpValidAreas;
    cTkVector3 mPlayerPosition;
    cTkVector3 mPlayerDirection;
    float mfCullDistance;
    float mbUseCulling;
    uint64_t mu64UniqueId;
    int miX;
    int miY;
    int miZ;
    int miMaxNumCalcsPerUpdate;
    int miLastNumCalcs;
    cTkBitArray<uint64_t, false, 0> mxGridGenerated;
    bool mbFirstGeneration;
    cGcAsteroidGenerationData mAsteroidGenerationData;
    eAsteroidType meAsteroidType;
};

class cGcAsteroidManager
{
  public:
    cTkFixedArray<TkID<128>, 4> maAsteroidSubstances;
    TkHandle mAsteroidRootNode;
    cTkSmartResHandle mAsteroidMaterial;
    cTkVoxelGeneratorData mAsteroidVoxelGeneratorData;
    robin_hood::detail::Table<true, 80, TkHandle, int, robin_hood::hash<TkHandle, void>, std::equal_to<TkHandle>>
        mAsteroidByNodeLookup;
    cTkSmartResHandle mRareAsteroidRes;
    cTkFixedArray<cTkSmartResHandle, 3> mCommonAsteroidRes;
    cTkFixedArray<unsigned char, 3> mUncommonAsteroidModelInstances;
    cTkSmartResHandle mRingAsteroidRes;
    bool mbDebugRareAsteroids;
    eAsteroidLevel meDebugRareAsteroidLevel;
    cTkPhysRelVec3 mPrevCamPos;
    float mfCurrentSpeed;
    int miAsteroidSystemGenerationDataIndex;
    cGcInstancedPhysicsAsteroidGrid *mpRareAsteroidGrid;
    cGcInstancedPhysicsAsteroidGrid *mapCommonAsteroidGrids[8];
    cGcVoxelAsteroidGrid<5> *mapLargeAsteroidGrids[1];
    cGcInstancedPhysicsAsteroidGrid *mapRingAsteroidGrid[1];
    cTkClassPool<cTkSphere, 32> maInvalidAreas;
    cTkClassPool<cGcAsteroidRing, 32> maValidAreas;
    bool mbEnabled;
    bool mbPhysicsDisabled;
    int miGridUpdateIndex;
    int miMaxNumCalcs;
    bool mbRareAsteroidSystem;
};

SKYSCRAPER_END