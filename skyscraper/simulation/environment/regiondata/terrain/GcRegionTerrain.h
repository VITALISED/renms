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