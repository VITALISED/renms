/**
 * @file GcPlanetControls.h
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

#include <toolkit/utilities/containers/TkBitArray.h>
#include <toolkit/utilities/random/TkPersonalRNG.h>

#include <simulation/ecosystem/gccreaturespawndata.meta.h>
#include <simulation/environment/gcbuildingclassification.meta.h>
#include <simulation/environment/gcobjectspawndata.meta.h>
#include <toolkit/tkpalettetexture.meta.h>

SKYSCRAPER_BEGIN

class cGcPlanet;

enum eTerrainAtlasTextures
{
    ETerrainAtlas_Base_Slope,
    ETerrainAtlas_Base,
    ETerrainAtlas_BaseAlt_Slope,
    ETerrainAtlas_BaseAlt,
    ETerrainAtlas_Mount_Slope,
    ETerrainAtlas_Mount,
    ETerrainAtlas_MountAlt_Slope,
    ETerrainAtlas_MountAlt,
    ETerrainAtlas_Detail_Base_Slope,
    ETerrainAtlas_Detail_Base,
    ETerrainAtlas_Detail_BaseAlt_Slope,
    ETerrainAtlas_Detail_BaseAlt,
    ETerrainAtlas_Detail_Mount_Slope,
    ETerrainAtlas_Detail_Mount,
    ETerrainAtlas_Detail_MountAlt_Slope,
    ETerrainAtlas_Detail_MountAlt,
    ETerrainAtlas_Num,
};

class cGcPlanetControls
{
  public:
    struct cGcPlanetGenerateRequest
    {
        bool mbRequired;
        eTerrainAtlasTextures mAtlasElement;
        ePalette mePalette;
        cGcObjectSpawnData *mpObjectData;
        cGcCreatureSpawnData *mpCreatureData;
        eTileType meTileType;
        cTkSeed mSeed;
    };

    cTkBitArray<unsigned int, true, 32> mTerrainNoiseLayers;
    cGcPlanetControls::cGcPlanetGenerateRequest maGenerateRequests[36];
    bool mbShowVisibilityOptions;
    bool mbShowColourOptions;
    float mfRegionGenerateStart;
    float mfRegionGenerateEnd;
    bool mbRegionGenerateActive;
    float mfEditDistance;
    bool mbEditPosition;
    eBuildingClass meTargetBuilding;
    cTkPersonalRNG mBuildingJumpRNG;
    uint8_t meBuildingJumpRequest[4];
    int miNumBuildingJumpAttempts;
    bool mbSwitchedToDebugCam;
    cGcPlanet *mpPlanet;
};

SKYSCRAPER_END