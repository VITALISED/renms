/*
    Copyright (C) 2023  VITALISED, tractorbeam

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <skyscraper.h>
#include <gamestate/GcPlayerShipOwnership.h>
#include <simulation/player/GcPersonalTeleporter.h>
#include <toolkit/attachments/TkHandle.h>
#include <toolkit/resources/TkSmartResHandle.h>
#include <toolkit/maths/numeric/generic/TkMatrix34Generic.h>
#include <toolkit/maths/numeric/generic/TkMatrix34Generic.h>
#include <metadata/simulation/vehicles/gcvehicletype.meta.h>
#include <metadata/simulation/player/gcscaneffectdata.meta.h>

SKYSCRAPER_BEGIN

struct VehicleInstance
{
	cGcProceduralTextureManager::TaskContext* mpTC;
	cTkSmartResHandle mPlayerVehicleResHandle;
	TkHandle mPlayerVehicleNode;
	cGcVehicleComponent* mpPlayerVehicleComponent;
	bool mbInSummoningRange;
	cTkMatrix34 mSpawnMatrix;
	bool mbSpawnPending;
	bool mbFancySpawn;
};

class cGcPlayerVehicleOwnership
{
	typedef cGcPlayerShipOwnership::eMeshRefreshState eMeshRefreshState;

	std::unordered_map<int, std::function<void __cdecl(eVehicleType, cTkMatrix34 const&)>> mNewVehicleSpawnCallbacks;
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