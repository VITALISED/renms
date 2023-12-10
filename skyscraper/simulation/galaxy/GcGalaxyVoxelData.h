/**
 * @file GcGalaxyVoxelData.h
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

#include <engine/extensions/galactic/TkGalacticExtension.h>
#include <simulation/galaxy/GcGalaxyTypes.h>
#include <simulation/galaxy/GcGalaxyVoxelTransitMesh.h>
#include <toolkit/maths/utilities/spatial/TkVector3KD.h>

SKYSCRAPER_BEGIN

class cGcGalaxyVoxelData
{
    std::vector<TkGalactic::ParticleInstanceData> mParticleStars;
    std::vector<TkGalactic::ParticleInstanceData> mParticleField;
    std::vector<TkGalactic::ParticleInstanceData> mCardInstances;
    cGcGalaxyVoxelTransitMesh mTransitMesh;
    cTkVector3MetaKD<uint64_t, 23> mSpatialCache;
};

class cGcGalaxyVoxel
{
  public:
    cGcGalaxyVoxelData mData;
    cGcGalacticVoxelCoordinate mCoordinate;
    uint64_t mu64UniverseAddress;
    int miGenerationID;
    char miCacheActivity;
    std::atomic<bool> mbInProgress;
};

SKYSCRAPER_END