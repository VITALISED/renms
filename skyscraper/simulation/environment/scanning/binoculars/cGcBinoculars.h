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
#include <simulation/environment/scanning/ScanInfo.h>
#include <graphics/ngui/GcNGuiText.h>
#include <toolkit/networking/TkUserIdBase.h>
#include <toolkit/simulation/physics/TkRaycastJob.h>
#include <toolkit/maths/numeric/TkSmoothCD.h>
#include <toolkit/utilities/containers/TkClassPool.h>
#include <toolkit/audio/wwise/TkAudioManagerWwise.h>
#include <toolkit/attachments/TkAttachment.h>

SKYSCRAPER_BEGIN

class cGcBinoculars
{
    class ScopeNodes
    {
        TkHandle mMainNode;
        TkHandle mScopeNode;
    };

    class sMissionSurvey
    {
        TkStrongType<int,TkStrongTypeIDs::TkResHandleID> mIcon;
        cTkAttachmentPtr mpClosestScannable;
        cTkAttachmentPtr mpScannableTarget;
        unsigned __int64 mLastUpdateTime;
        float mfCurrentDistance;
        bool mbLookingForScannable;
        bool mbHasCloseUnsurveyedScanEvent;
        bool mbClosestEventIsOffWorld;
        TkID<128> mCurrentMissionID;
    };

    enum eTargetScan
    {
        ETargetScan_None,
        ETargetScan_Scanning,
        ETargetScan_Displayed
    };

    enum eMode
    {
        EMode_ScanMode,
        EMode_MissionSurvey,
        EMode_PowerHotspots,
        EMode_MineralHotspots,
        EMode_GasHotspots,
        EMode_NumModes
    };

    cTkSmartResHandle mScannerScopeRes;
    cTkSmartResHandle mScannerScopeSurveyRes;
    TkHandle mScanNodeGroup;
    cGcBinoculars::ScopeNodes mScannerScopeNodes;
    cGcBinoculars::ScopeNodes mSurveyScopeNodes;
    float mfCrosshairDistanceSmoothed;
    bool mbPlayerOnPlanet;
    float mfScanProgress;
    float mfStatusDotsProgress;
    float mfSonarProgress;
    float mfGrowTime;
    std::vector<cGcNGuiText *,TkSTLAllocatorShim<cGcNGuiText *,8,-1> > mapGrowTexts;
    DiscoveryResolver::DiscoveryInfo mCurrentDiscoveryInfo;
    bool mbCurrentDiscoveryUnknown;
    cTkUserIdBase<cTkFixedString<64,char> > mMPMissionPlayerWhoScanned;
    float mfDampenedDistanceValue;
    float mfDiscoveryWindowActiveTime;
    float mfDiscoveryWindowDeactivateTime;
    cGcBinoculars::eTargetScan meTargetMode;
    unsigned __int64 mCurrentPlanet;
    cTkRaycastJob mRaycastJob;
    cGcSimpleScanEffectPool<3> mHighlightEffects;
    cTkClassPoolHandle mInfoPanelScreen;
    ScanInfo mMarkerInfo;
    ScanInfo mTargetInfo;
    bool mbTargetingWasHeld;
    cTkVector2 mTargetScreenPos;
    cTkSmoothCD<float> mfTargetScreenHeight;
    float mfTargetStartTime;
    cTkPhysRelVec3 mTargetSmoothedCentre;
    cTkVector3 mTargetSmoothedCentreVel;
    bool mbTargetDiscovered;
    cTkMatrix34 mSmoothScopeMatrix;
    std::vector<TkHandle,TkSTLAllocatorShim<TkHandle,4,-1> > maFadingMarkers;
    TkHandle mMarkerModel;
    cGcBinoculars::eMode meMode;
    float mfBinocsLastUsedTime;
    float mfAtmosphereEntryErrorTimer;
    TkAudioObject mAudioObject;
    cGcBinoculars::sMissionSurvey mMissionSurvey;
    cGcNGui *mpBinocularInfoGui;
    cGcNGui *mpBinocularMarkerGui;
    cGcNGui *mpDiscoveryGui;
    cGcNGuiLayer *mpCentreLayer;
    cGcNGuiLayer *mpModesLayer;
    cGcNGuiLayer *mpModesSmallLayer;
    cGcRegionHotspots::eHotspotCategory meCurrentHotspotCategory;
    bool mbCurrentHotspotDiscovered;
};

SKYSCRAPER_END