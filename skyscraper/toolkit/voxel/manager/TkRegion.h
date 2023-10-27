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
#include <toolkit/voxel/TkVoxelVertexDefinition.h>
#include <toolkit/attachments/TkHandle.h>
#include <toolkit/resources/TkSmartResHandle.h>
#include <toolkit/maths/numeric/generic/TkVector3Generic.h>
#include <toolkit/maths/numeric/generic/TkMatrix34Generic.h>
#include <toolkit/utilities/TkString.h>
#include <toolkit/graphics/TkColour.h>

SKYSCRAPER_BEGIN

enum eRegionStatus
{
	EStatus_Unassigned,
	EStatus_Empty,
	EStatus_RequiredForGeneration,
	EStatus_Generating,
	EStatus_Generated,
	EStatus_MapStreams,
	EStatus_CheckResourcesLoaded,
	EStatus_ReadyToPolygonise,
	EStatus_Polygonising,
	EStatus_Polygonised,
	EStatus_ReadyToPostPolygonise,
	EStatus_PostPolygonised,
	EStatus_ReadyToPopulate,
	EStatus_ReadyToBuildKnowledge,
	EStatus_KnowledgeBuilding,
	EStatus_KnowledgeBuilt,
	EStatus_Completed,
	EStatus_Clearing,
	EStatus_NumStatus,
	EStatus_Renderable,
};

class cTkRegion
{
	cTkRegionMapBase* mpRegionMap;
	cTkVoxelArray* mpRegionData;
	TkHandle mNode;
	TkHandle mParentNode;
	cTkSmartResHandle mResource;
	eRegionStatus meStatus;
	bool mbEdited;
	bool mbClearRequested;
	bool mbEmpty;
	bool mbPendingEditUpdate;
	bool mbPendingRefresh;
	bool mbPendingKnowledgeRefresh;
	int miScaleX;
	int miScaleY;
	int miScaleZ;
	int miOffsetX;
	int miOffsetY;
	int miOffsetZ;
	int miSizeX;
	int miSizeY;
	int miSizeZ;
	int miVoxelsX;
	int miVoxelsY;
	int miVoxelsZ;
	int miDiameter;
	int miBorder;
	cTkVector3 mNormal;
	cTkMatrix34 mCubeMatrix;
	int mxTileFlags;
	cTkFixedString<64, char> mDebugName;

	virtual ~cTkRegion();
	virtual void Construct(TkHandle, cTkRegionMapBase*, cTkVoxelArray*, int);
	virtual void Destruct();
	virtual void UpdateMatrix();
	virtual void Assign(int, int, int, int, int, int, int, int, int, int, int, int, int, int, const cTkVector3*, const char*);
	virtual void PostPolygonise();
	virtual void PostPolygonisePopulate();
	virtual void KnowledgeBuilt();
	virtual bool PollToUnmapStreams();
	virtual bool TryToClear();
	virtual void Invalidate();
	virtual void Clear();
	virtual void RefreshKnowledge();
	virtual void RefreshFoliage();
	virtual const char* GetResource();
	virtual cTkColour* GetStatusColour(cTkColour* result);
	virtual bool GenerateVoxels();
	virtual bool Polygonise();
	virtual bool BuildKnowledge();
	virtual void InvalidateKnowledge();
	virtual bool AreResourcesLoaded();
};

class cTkRegionMapBase
{
	virtual int GetScaleX();
	virtual int GetScaleY();
	virtual int GetScaleZ();
	virtual cTkVector3* GetCentre(cTkVector3* result);
};


SKYSCRAPER_END