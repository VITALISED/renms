/**
 * @file GcBuilding.h
 * @author VITALISED & Contributors
 * @since 2023-12-06
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

#include <simulation/scenemanager/GcFadeNode.h>
#include <toolkit/attachments/TkAttachment.h>
#include <toolkit/maths/numeric/generic/TkMatrix34Generic.h>

#include <simulation/environment/gcbuildingspawndata.meta.h>

SKYSCRAPER_BEGIN

class cGcRegionTerrainFar;
class cGcWFCBuildingState;
class cGcPlanet;
class cGcRegionTerrain;

class cGcBuilding
{
  public:
    enum ePlacementState
    {
        EPlacementState_Invalid,
        EPlacementState_Listed,
        EPlacementState_Setup,
        EPlacementState_Placed,
        EPlacementState_Upgraded,
    };

    enum eScanState
    {
        EScanState_Unknown,
        EScanState_Scanned,
        EScanState_Visited,
    };

    cTkMatrix34 mSpawnTM;
    cGcFadeNode mFadeNode;
    cGcRegionTerrain *mpRegion;
    cGcPlanet *mpPlanet;
    cGcBuildingSpawnData *mpData;
    TkHandle mNode;
    cTkAttachmentPtr mpAttachment;
    cGcWFCBuildingState *mpWFCState;
    float mfDistanceSquared;
    float mfArcDistance;
    cTkSeed mSeed;
    cGcBuilding::ePlacementState mePlacementState;
    cGcBuilding::eScanState meScanState;
    cGcRegionTerrainFar *mpOwningRegion;
    cTkSeed maSurroundingBuildings[40];
    int miClusterIndex;
};

SKYSCRAPER_END