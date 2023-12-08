/**
 * @file GcGalaxyVoxelCache.h
 * @author VITALISED & Contributors
 * @since 2023-12-09
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

#include <simulation/galaxy/GcGalaxyVoxelData.h>
#include <toolkit/maths/utilities/spatial/TkVector3KD.h>
#include <toolkit/system/TkCSMutex.h>
#include <toolkit/utilities/containers/TkStackContainer.h>
#include <toolkit/utilities/containers/TkTFixedFreeList.h>

SKYSCRAPER_BEGIN

class cGcGalaxyVoxelCache
{
  public:
    struct VoxelRetirement
    {
        cGcGalacticVoxelCoordinate mCoordinate;
    };

    cTkCSMutex mOperationSerializeMutex;
    std::atomic<unsigned int> mauTasksInFlight;
    std::atomic<unsigned short> mau16GenerationID;
    cTkTFixedFreeList<cGcGalaxyVoxel, 23> mVoxelFreeList;
    cTkVector<cGcGalaxyVoxel *> mActiveVoxels;
    cTkStackVector<cGcGalaxyVoxelCache::VoxelRetirement, 4> mVoxelRetirementCache;
    cTkVector3MetaKD<unsigned __int64, 23> mSpatialDB;
    nanoflann::KDTreeSingleIndexAdaptor<
        nanoflann::L2_Simple_Adaptor<float, cTkVector3MetaKD<uint64_t, 23>, float>, cTkVector3MetaKD<uint64_t, 23>, 3,
        uint64_t>
        mSpatialTree;
    std::atomic<bool> mabSpatialBuilding;
    std::atomic<bool> mabSpatialValid;
    cGcGalacticVoxelCoordinate mLastSpatialGC;
    unsigned int muCacheVersioning;
    float mfTimeStable;
};

SKYSCRAPER_END