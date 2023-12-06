/**
 * @file GcScanner.h
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

#include <simulation/environment/scanning/GcBinoculars.h>
#include <simulation/environment/scanning/GcMarkerPoint.h>
#include <simulation/solarsystem/buildings/GcBuilding.h>
#include <toolkit/attachments/TkAttachment.h>
#include <toolkit/audio/wwise/TkAudioManagerWwise.h>
#include <toolkit/core/types/TkHandle.h>
#include <toolkit/maths/geometry/TkAABB.h>
#include <toolkit/maths/geometry/TkPhysRelVec3.h>
#include <toolkit/maths/numeric/generic/TkMatrix34Generic.h>
#include <toolkit/maths/numeric/generic/TkVector3Generic.h>
#include <toolkit/resources/TkResource.h>
#include <toolkit/utilities/containers/TkStackContainer.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <simulation/player/gcscandata.meta.h>
#include <toolkit/voxel/generator/tknoisevoxeltypeenum.meta.h>

SKYSCRAPER_BEGIN

class ScannedNode
{
  public:
    enum eDressRequest
    {
        NeedsDressing,
        NeedsUniqueSmartDressing,
        NoDressingNeeded,
    };
    TkHandle mScannedNode;
    cTkColour mColour;
    float (*mScanColourCallback)(const ScannedNode *);
    float (*maScanValueCallbacks[4])(const ScannedNode *);
    float mfActiveTime;
    float mfLifeTime;
    ScannedNode::eDressRequest meDressRequest;
    const cGcScanEffectData *mpData;
};

class cGcScannedNodesList
{
  public:
    robin_hood::detail::Table<
        false, 80, unsigned int, ScannedNode, robin_hood::hash<unsigned int, void>, std::equal_to<unsigned int>>
        maScannedNodes;
};

class cGcScanner
{
  public:
    struct SortableScanData
    {
        float mfSortValue;
        TkHandle mNodeHandle;
        float mfDotToNode;
        float mfDistance;
    };

    struct TerrainResourcePosition
    {
        cTkVector3 mBasePosition;
        cTkVector3 mElevatedPosition;
        eNoiseVoxelType mSubstance;
    };

    struct FuelAsteroidInfo
    {
        enum eState
        {
            PendingMarker,
            MarkerAdded,
            PendingDestroy,
        };

        cGcScanner::FuelAsteroidInfo::eState meState;
        cTkPhysRelVec3 mvPos;
        cTkAABB mOBB;
    };

    struct ScannerRoutineInfo
    {
        cTkVector<cTkPhysRelVec3> maRoutineCreaturePositions;
        cTkVector<float> maRoutineCreatureTimes;
    };

    struct ScannerCreatureInfo
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
    std::vector<cGcBuilding *> mHoveredObjects;
    std::vector<cGcBuilding *> mScannedBuildings;
    cGcMarkerPoint mCurrentObjectHighlight;
    std::array<cGcScanner::SortableScanData, 180> mTemporarySortableScanDataArray;
    cGcScannedNodesList mScannedNodesList;
    cTkVector<cGcScanner::TerrainResourcePosition> mScannableTerrainResources;
    cTkStackVector<cGcScanner::FuelAsteroidInfo, 32> mScannableFuelAsteroids;
    float mfRangeMultiplier;
    bool mbIsZooming;
    cGcMarkerList *mpMarkerList;
    cGcScanner::ScannerRoutineInfo mScannerRoutineInfo;
    cTkVector<cGcScanner::ScannerCreatureInfo> maCreatureInfo;
    cGcBinoculars mBinoculars;
    cGcSimpleScanEffect mBinocularScan;
    uint64_t mCurrentPlanetUA;
};

SKYSCRAPER_END