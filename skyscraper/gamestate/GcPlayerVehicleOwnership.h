#pragma once

#include <skyscraper.h>
#include <gamestate/GcPlayerShipOwnership.h>
#include <simulation/player/GcPersonalTeleporter.h>
#include <toolkit/attachments/TkHandle.h>
#include <toolkit/resources/TkSmartResHandle.h>
#include <toolkit/maths/numeric/generic/TkMatrix34Generic.h>
#include <toolkit/maths/numeric/generic/TkMatrix34Generic.h>
#include <metadata/source/simulation/vehicles/gcvehicletype.meta.h>
#include <metadata/source/simulation/player/gcscaneffectdata.meta.h>

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