/**
 * @file GcPlanetLodSphere.h
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

#include <toolkit/maths/geometry/TkAABB.h>
#include <toolkit/resources/TkResource.h>
#include <toolkit/utilities/containers/TkBitArray.h>
#include <toolkit/voxel/terrain/TkTerrainVertex.h>

#include <toolkit/voxel/generator/tkvoxelgeneratordata.meta.h>

SKYSCRAPER_BEGIN

class cGcPlanet;

class cGcPlanetLodSphere
{
  public:
    enum EGenStage
    {
        eGS_Idle,
        eGS_Running,
    };

    struct sBuildParams
    {
        int miFaceIndex;
        int miStartX;
        int miStartZ;
        cTkTerrainVertexData *mpVertexData;
        uint8_t *mpPixelData;
        cTkAABB mBoundingBox;
        float mfPlanetRadius;
        float mfPlanetSeaLevel;
        cTkVoxelGeneratorData *mpPlanetVoxelGeneratorData;
        std::atomic<int> miStatus;
    };

    cGcPlanet *mpPlanet;
    cTkSmartResHandle mTerrainResource;
    cTkBitArray<uint64_t, true, 384> mFacesRendered;
    cTkSmartResHandle mTerrainMaterial;
    cGcPlanetLodSphere::EGenStage meGenStage;
    cGcPlanetLodSphere::sBuildParams mActiveJobParams[64];
    cTkSmartResHandle mSphereCubemap;
    int miMappedBuffer;
    uint8_t *mpTextureBuffer;
    int giMaxActiveJobs;
};

SKYSCRAPER_END