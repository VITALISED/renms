/**
 * @file GcPlayerVehicleOwnership.h
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

#include <graphics/2d/GcProceduralTexture.h>
#include <simulation/player/GcPersonalTeleporter.h>
#include <toolkit/maths/numeric/generic/TkMatrix34Generic.h>

#include <simulation/player/gcscaneffectdata.meta.h>
#include <simulation/vehicles/gcvehicletype.meta.h>

SKYSCRAPER_BEGIN

struct VehicleInstance
{
    cGcProceduralTextureManager::TaskContext *mpTC;
    cTkSmartResHandle mPlayerVehicleResHandle;
    TkHandle mPlayerVehicleNode;
    /*cGcVehicleComponent*/ uintptr_t *mpPlayerVehicleComponent;
    bool mbInSummoningRange;
    cTkMatrix34 mSpawnMatrix;
    bool mbSpawnPending;
    bool mbFancySpawn;
};

class cGcPlayerVehicleOwnership
{
  public:
    enum eMeshRefreshState
    {
        ReadyForRefresh,
        Generating,
        SwapMesh,
    };

    std::unordered_map<int, std::function<void(eVehicleType, cTkMatrix34 const &)>> mNewVehicleSpawnCallbacks;
    TkHandle mGroupRootNode;
    VehicleInstance maVehicles[7];
    eVehicleType meRequestVehicle;
    cTkMatrix34 mRequestedVehicleMatrix;
    cGcPlacementArc mPlacementArc;
    eVehicleType meShowPreview;
    cGcScanEffectData mPreviewScanData;
    cTkColour mPreviewColour;
    float mfPreviewFirstActiveTime;
    float mfPreviewLastActiveTime;
    TkHandle mPreviewNode;
    bool mbClearPreview;
    bool mbShowRocketPreview;
    bool mbShouldRefreshMesh;
    cGcPlayerVehicleOwnership::eMeshRefreshState mMeshRefreshState;
    cTkSmartResHandle mRefreshSwapRes;
};

SKYSCRAPER_END