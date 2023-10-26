#pragma once

#include <skyscraper.h>
#include <simulation/environment/regiondata/GcRegion.h>
#include <simulation/scenemanager/GcFadeNode.h>
#include <toolkit/voxel/terrain/TkTerrainVertex.h>
#include <toolkit/voxel/generator/basic/TkBasicNoiseHelper.h>
#include <toolkit/maths/geometry/TkAABB.h>
#include <toolkit/utilities/containers/TkVector.h>

SKYSCRAPER_BEGIN

enum ePolygoniser
{
	EPolygoniser_DualContouring,
	EPolygoniser_MarchingCubes,
	EPolygoniser_Heightmap,
	EPolygoniser_NumPolygonisers,
};

class cGcRegionTerrain : public cGcRegionBase
{
	ePolygoniser mePolygoniser;
	cTkTerrainVertexData* mpMappedStreamTerrain;
	bool mbNeedsOverflowStream;
	bool mbDeferEditsGeneration;
	int miNumTerrainVerts;
	int miDistance;
	int miParentDistance;
	float mfAngle;
	cTkSmartResHandle mTerrainMaterial;
	cTkSmartResHandle mWaterMaterial;
	cTkAABB mBoundingBox;
	cGcRegionTerrain* mpParent;
	cGcRegionTerrain* maChildren[8];
	float* mpaafMaxHeights;
	float* mpaafElevation;
	cGcFadeNode mFade;
	int miLod;
	int miTileBlendStart;
	cTkVector<cTkBasicNoiseHelper::NoisePositionData> mResourcePositions;
	cTkVector3 mAbsolutePosition;
};

SKYSCRAPER_END