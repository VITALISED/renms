/**
 * @file GcBinoculars.h
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

#include <gamestate/GcDiscoverySearch.h>
#include <graphics/ngui/GcNGuiManager.h>
#include <graphics/ngui/GcNGuiText.h>
#include <simulation/environment/scanning/GcRegionHotspots.h>
#include <simulation/environment/scanning/GcSimpleScanEffect.h>
#include <toolkit/attachments/TkAttachment.h>
#include <toolkit/audio/wwise/TkAudioManagerWwise.h>
#include <toolkit/core/types/TkHandle.h>
#include <toolkit/core/types/TkTypes.h>
#include <toolkit/networking/TkUserIdBase.h>
#include <toolkit/resources/TkResource.h>
#include <toolkit/simulation/physics/TkRaycastJob.h>
#include <toolkit/utilities/containers/TkVector.h>

SKYSCRAPER_BEGIN

struct ScanInfo
{
    TkHandle mModelNode;
    cTkAttachmentPtr mpAttachment;
    cTkRigidBodyPtr mpBody;
    bool mbUnknown;
    bool mbAlwaysKnown;
};

class cGcBinoculars
{
  public:
    enum eMode
    {
        EMode_ScanMode,
        EMode_MissionSurvey,
        EMode_PowerHotspots,
        EMode_MineralHotspots,
        EMode_GasHotspots,
        EMode_NumModes,
    };

    enum eTargetScan
    {
        ETargetScan_None,
        ETargetScan_Scanning,
        ETargetScan_Displayed,
    };

    struct ScopeNodes
    {
        TkHandle mMainNode;
        TkHandle mScopeNode;
    };

    struct sMissionSurvey
    {
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> mIcon;
        cTkAttachmentPtr mpClosestScannable;
        cTkAttachmentPtr mpScannableTarget;
        uint64_t mLastUpdateTime;
        float mfCurrentDistance;
        bool mbLookingForScannable;
        bool mbHasCloseUnsurveyedScanEvent;
        bool mbClosestEventIsOffWorld;
        TkID<128> mCurrentMissionID;
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
    cTkVector<cGcNGuiText *> mapGrowTexts;
    DiscoveryResolver::DiscoveryInfo mCurrentDiscoveryInfo;
    bool mbCurrentDiscoveryUnknown;
    cTkUserIdBase<cTkFixedString<64, char>> mMPMissionPlayerWhoScanned;
    float mfDampenedDistanceValue;
    float mfDiscoveryWindowActiveTime;
    float mfDiscoveryWindowDeactivateTime;
    cGcBinoculars::eTargetScan meTargetMode;
    uint64_t mCurrentPlanet;
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
    cTkVector<TkHandle> maFadingMarkers;
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