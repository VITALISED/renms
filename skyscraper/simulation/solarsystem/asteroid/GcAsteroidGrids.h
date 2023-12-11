/**
 * @file GcAsteroidGrids.h
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

#include <simulation/solarsystem/asteroid/GcAsteroid.h>
#include <simulation/solarsystem/asteroid/GcAsteroidPatternGenerator.h>
#include <toolkit/maths/geometry/TkSphere.h>
#include <toolkit/utilities/containers/TkBitArray.h>
#include <toolkit/utilities/containers/TkClassPool.h>

#include <simulation/gcasteroidgenerationdata.meta.h>

SKYSCRAPER_BEGIN

template <int MemPoolIdx>
class cGcAsteroidGrid
{
  public:
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
    cTkBitArray<uint64_t, true, 125> mxGridGenerated;
    bool mbFirstGeneration;
    cGcAsteroidGenerationData mAsteroidGenerationData;
};

template <int MemPoolIdx>
class cGcVoxelAsteroidGrid : public cGcAsteroidGrid<MemPoolIdx>
{
  public:
    std::array<float, 125> mafActiveTimes;
    std::array<cGcAsteroid, 125> maData;
    cTkBitArray<uint64_t, 1, 125> mxVoxelGenerated;
    cTkBitArray<uint64_t, 1, 125> mxValidity;
};

SKYSCRAPER_END