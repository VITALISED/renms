#pragma once

#include <skyscraper.h>
#include <simulation/scenemanager/GcFadeNode.h>
#include <simulation/environment/regiondata/terrain/GcRegionTerrain.h>
#include <toolkit/maths/numeric/generic/TkMatrix34Generic.h>
#include <toolkit/simulation/TkSeed.h>

SKYSCRAPER_BEGIN

class cGcBuilding
{
	cTkMatrix34 mSpawnTM;
	cGcFadeNode mFadeNode;
	cGcRegionTerrain* mpRegion;
	cGcPlanet* mpPlanet;
	cGcBuildingSpawnData* mpData;
	TkHandle mNode;
	cTkAttachmentPtr mpAttachment;
	cGcWFCBuildingState* mpWFCState;
	float mfDistanceSquared;
	float mfArcDistance;
	cTkSeed mSeed;
	cGcBuilding::ePlacementState mePlacementState;
	cGcBuilding::eScanState meScanState;
	cGcRegionTerrainFar* mpOwningRegion;
	cTkSeed maSurroundingBuildings[40];
	int miClusterIndex;
};

SKYSCRAPER_END