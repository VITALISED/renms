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
#include <robin_hood.h>
#include <simulation/environment/scanning/binoculars/cGcBinoculars.h>
#include <toolkit/audio/wwise/TkAudioManagerWwise.h>
#include <toolkit/maths/numeric/generic/TkMatrix34Generic.h>
#include <toolkit/maths/geometry/TkAABB.h>
#include <toolkit/system/TkMemoryManager.h>
#include <toolkit/attachments/TkAttachment.h>
#include <simulation/solarsystem/buildings/GcBuilding.h>
#include <simulation/environment/scanning/GcMarkerPoint.h>

//metadata
#include <voxel/generator/tknoisevoxeltypeenum.meta.h>

SKYSCRAPER_BEGIN

class cGcScannedNodesList
{
    struct ScannedNode
    {
        TkHandle mNodeHandle;
        float mfDotToNode;
        float mfDistance;
    };
    
    robin_hood::unordered_flat_map<unsigned __int64,cGcScannedNodesList::ScannedNode> mScannedNodes;
};

class cGcMarkerList
{
  std::vector<cGcMarkerPoint,TkSTLAllocatorShim<cGcMarkerPoint,16,-1> > maMarkerObjects;
};

class cGcScanner
{
	class SortableScanData
	{
		float mfSortValue;
		TkHandle mNodeHandle;
		float mfDotToNode;
		float mfDistance;
	};

    class TerrainResourcePosition {
        cTkVector3 mBasePostion;
        cTkVector3 mElevatedPosition;
        eNoiseVoxelType mSubstance;
    };

    class FuelAsteroidInfo {
        enum eState {
            PendingMarker,
            MarkerAdded,
            PendingDestroy
        };

        eState meState;
        cTkPhysRelVec3 mvPos;
        cTkAABB mOBB;
    };

    class ScannerRoutineInfo
    {
        std::vector<cTkPhysRelVec3,TkSTLAllocatorShim<cTkPhysRelVec3,16,-1> > maRoutineCreaturePositions;
        std::vector<float,TkSTLAllocatorShim<float,4,-1> > maRoutineCreatureTimes;
    };

    class ScannerCreatureInfo
    {
        cTkPhysRelVec3 mPosition;
        bool mbDiscovered;
        float mfTime;
        cTkAttachmentPtr mAttachment;
    };

	TkAudioObject mScannerAudioObject;
	cTkSmartResHandle mResLineMaterial;
	cTkSmartResHandle mResLightMaterial;
	float mfScannerCharge;
	unsigned int miScannerUIDCounter;
	float mfScanStartTime;
	cTkVector3 mScanCentre;
	float mfScanProgression;
	float mfScanLiveBlendValue;
	float mfScanTime;
	float mfScanDisplayedTime;
	bool mbPlayedScanAudio;
	cTkMatrix34 mScanBase;
	cTkAABB mScanAABB;
	bool mbScanLive;
	const cGcScanData *mpData;
	bool mbSubstanceScanLive;
	bool mbSubstanceScanDisplay;
	float mfSubstanceScanTime;
	float mfSubstanceDisplayValue;
	int miHoveredBuilding;
	float mfHoveredBuildingTime;
	std::vector<cGcBuilding *,TkSTLAllocatorShim<cGcBuilding *,8,-1> > mHoveredObjects;
	std::vector<cGcBuilding *,TkSTLAllocatorShim<cGcBuilding *,8,-1> > mScannedBuildings;
	__declspec(align(16)) cGcMarkerPoint mCurrentObjectHighlight;
	std::array<cGcScanner::SortableScanData,180> mTemporarySortableScanDataArray;
	cGcScannedNodesList mScannedNodesList;
	std::vector<cGcScanner::TerrainResourcePosition,TkSTLAllocatorShim<cGcScanner::TerrainResourcePosition,16,-1> > mScannableTerrainResources;
	cTkStackVector<cGcScanner::FuelAsteroidInfo,32,-1> mScannableFuelAsteroids;
	float mfRangeMultiplier;
	bool mbIsZooming;
	cGcMarkerList *mpMarkerList;
	cGcScanner::ScannerRoutineInfo mScannerRoutineInfo;
	std::vector<cGcScanner::ScannerCreatureInfo,TkSTLAllocatorShim<cGcScanner::ScannerCreatureInfo,16,-1> > maCreatureInfo;
	__declspec(align(16)) cGcBinoculars mBinoculars;
	cGcSimpleScanEffect mBinocularScan;
	unsigned __int64 mCurrentPlanetUA;
};

SKYSCRAPER_END