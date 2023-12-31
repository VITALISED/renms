/**
 * @file GcPlanetCommon.h
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

#include <toolkit/utilities/containers/TkVector.h>

#include <simulation/environment/gcobjectspawndata.meta.h>

SKYSCRAPER_BEGIN

class cGcPlanetObjectSpawnData
{
  public:
    cGcObjectSpawnData *mpSpawnData;
    cGcResourceElement mResource;
    cTkDynamicArray<cGcResourceElement> maAltResources;
    cGcTerrainTileType mTileType;
    bool mbAllowLimiting;
    int miCachedCollisionNodeCount;
    bool mbEnabled;
};

class cGcPlanetSpawnData
{
  public:
    cTkVector<cGcPlanetObjectSpawnData> maDistantObjects;
    cTkVector<cGcPlanetObjectSpawnData> maLandmarks;
    cTkVector<cGcPlanetObjectSpawnData> maObjects;
    cTkVector<cGcPlanetObjectSpawnData> maDetailObjects;
    bool mbDistantObjectsEnabled;
    bool mbLandmarksEnabled;
    bool mbObjectsEnabled;
    bool mbDetailObjectsEnabled;
};

SKYSCRAPER_END