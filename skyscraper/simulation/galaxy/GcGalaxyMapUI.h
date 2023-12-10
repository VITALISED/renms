/**
 * @file GcGalaxyMapUI.h
 * @author VITALISED & Contributors
 * @since 2023-12-09
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

#include <gamestate/GcDiscoveryCommon.h>
#include <gamestate/GcDiscoverySearch.h>
#include <graphics/ngui/GcNGuiLayer.h>
#include <graphics/ngui/GcNGuiTextSpecial.h>
#include <simulation/galaxy/GcGalaxyTypes.h>
#include <toolkit/audio/wwise/TkAudioManagerWwise.h>
#include <toolkit/utilities/containers/TkClassPool.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/utilities/random/TkPersonalRNG.h>

#include <simulation/galaxy/gcgalaxyinfoicons.meta.h>

SKYSCRAPER_BEGIN

enum GalaxyNavigationMode
{
    Invalid = -1,
    JourneyToCenter,
    FreeFlight,
    UserWaypoint,
    BlackHole,
    Atlas,
    UserMission,
    SeasonParty,
    NumModes,
};

struct WarpCapabilityResult
{
    enum Result
    {
        Invalid,
        ValidJump,
        NoJumpRequired,
        OtherPlayerFleetAtDestination,
        PortalInterference,
        NoFuel,
        InsufficientDrivePower,
        NoWarpDrive,
        WarpDriveBroken,
        AnomaliesNotUnlocked,
        IncompleteCriticalMissions,
        RedStarTypeNotUnlocked,
        RedStarTypeNotUnlocked_Freighter,
        GreenStarTypeNotUnlocked,
        GreenStarTypeNotUnlocked_Freighter,
        BlueStarTypeNotUnlocked,
        BlueStarTypeNotUnlocked_Freighter,
    };

    float lfJumpDistanceLightyears;
    float lfJumpAmountCapable;
    WarpCapabilityResult::Result leResult;
};

class cGcGalaxyMapUI
{
  public:
    enum ScanState
    {
        Idle,
        Scanning,
        Selectable,
        Disabled,
    };

    struct NavModeHelperText
    {
        GalaxyNavigationMode meLastKnownMode;
        float mfDisplayTimeout;
        float mfAlpha;
    };

    struct SolarSelectionLocation
    {
        cTkVector3 mPosition;
        cGcGalacticVoxelCoordinate mCoordinate;
    };

    struct SolarSelectionData
    {
        cGcDiscoveryData mSolarDiscoveryData;
        DiscoveryResolver::NameAndOwnerResult mNameAndOwner;
        cTkFixedString<127, char> mGalacticRegionName;
        WarpCapabilityResult mWarpCapability;
        float mfDistancetoCenter;
        cGcGalaxyStarAttributesData mClassification;
        cGcGalaxyMapUI::SolarSelectionLocation mLocation;
        bool mbHasWater;
        bool mbHasFrequentWorms;
        bool mbServerRequestIssued;
        uint16_t mVisitedPlanets;
    };

    struct SolarInfoPanel
    {
        enum PanelState
        {
            Hidden,
            Prepare,
            PrepareGalaxyCentre,
            Active,
            Disappear,
        };

        enum SolarInfoState
        {
            Waiting,
            Covering,
            Uncovering,
            Finished,
        };

        cTkPersonalRNG mRNG;
        float mfTime;
        TkAudioObject mHostAudioObject;
        float mfDisplayCountdown;
        float mfSelectTime;
        cGcNGuiLayer mInfoPanelRoot;
        cGcNGuiLayer mTooltips[2];
        cGcNGuiLayer *mTooltipRoot;
        bool mbTooltipExpanded;
        bool mbCurrentTooltip;
        float mfPanelHeightCurrent;
        float mfPanelHeightTarget;
        float mfContentLayerHeight;
        cGcNGuiLayer *mpTopBarLayer;
        cGcNGuiLayer *mpTitleLayer;
        cGcNGuiLayer *mpContentLayer;
        cTkVector<cGcNGuiLayer *> mBlobPanelsToAdd;
        cTkVector<cGcNGuiLayer *> mBlobPanels;
        cTkVector<cGcNGuiLayer *> mBlobPanelTopBars;
        std::array<float, 12> mBlobValues;
        std::array<cGcNGuiLayer *, 3> mInterestingBlobs;
        float mfTimeTillBlobPanel;
        cGcGalaxyMapUI::SolarInfoPanel::PanelState mePanelState;
        float mfPanelAppearT;
        float mfDiscoveryDataBlobFxT;
        cTkFixedString<127, char> mSolarTitleNameReplacement;
        float mfTitleNameReplacementFade;
        cGcGalaxyMapUI::SolarSelectionLocation mCurrentLocationData;
        uint64_t mCurrentLocationUA;
        cGcGalaxyMapUI::SolarSelectionData mSolarDataAwaitingBuild;
        bool mbIsSolarDataAwaitingBuild;
        cGcGalaxyMapUI::SolarInfoPanel::SolarInfoState mbSolarInfoState;
        bool mbIsSolarInfoAwaitingAssignment;
        bool mbSolarInfoValid;
        bool mbAudioTrigger;
        bool mbHasSelection;
        bool mbSelectionIsValidWarp;
        const cGcGalaxyInfoIcons *mpGalaxyInfoIcons;
    };

    struct MessageData
    {
        float mfTimer;
        float mfDelay;
        bool mbVisible;
        cTkFixedString<512, char> macTitle;
        cTkFixedString<512, char> macSubtitle;
        TkAudioID mAudioEventID;
    };

    struct NavigationStateData
    {
        enum SlotState
        {
            Unused,
            Searching,
            Available,
            Selected,
        };
        std::array<cGcGalaxyMapUI::NavigationStateData::SlotState, 7> mWaypointSlots;
    };

    struct NavigationStateDataDisplay
    {
        float mfTime;
        float mfVisibility;
        float mfTooManyWaypointsErrorPulse;
    };

    GalaxyNavigationMode meCurrentNavigationMode;
    uint8_t meCurrentFilterMode[4];
    uint8_t meLastKnownFilterMode[4];
    cGcGalaxyMapUI::NavModeHelperText mNavModeHelperText;
    cTkClassPoolHandle mInWorldSolarScreen;
    cTkVector3 mSelectionPosition;
    cGcGalaxyMapUI::SolarInfoPanel mSolarInfoPanel;
    cGcNGuiLayer mDiscoveryRoot;
    cGcNGuiLayer mGalaxyBarLayer;
    cGcNGuiLayer *mpLowerBarLowerRoot;
    cGcNGuiTextSpecial *mpLowerBarHelpText;
    cGcNGuiLayer *mpLowerBarPathSelector;
    cGcNGuiLayer *mpPathReturnHelpLayer;
    cGcNGuiLayer *mpHelpScanBg;
    cGcNGuiLayer *mpNavigationModeLayer;
    cGcNGuiLayer *mpFilterModeLayer;
    float mfLastNavModeSelectTime;
    float mfLastFilterModeSelectTime;
    cGcNGuiTextSpecial *mpHelpTextScan;
    float mfVisibilityPrimary;
    float mfVisibilitySecondary;
    bool mbBarVisibleToggle;
    bool mbScanEffectDisplay;
    float mfScanEffectAlpha;
    float mfScanEffectTime;
    float mfScanTextAlpha;
    float mfScanTextPulse;
    cTkFixedString<32, char> mScanTextReplacement;
    cGcGalaxyMapUI::ScanState meScanState;
    float mfShowUIHelpTime;
    cTkPersonalRNG mScanRNG;
    cTkFixedArray<float, 6> maScanTargets;
    cTkFixedArray<float, 6> maScanRandoms;
    cTkFixedArray<float, 6> maScanTimers;
    cTkFixedArray<cGcGalaxyMapUI::MessageData, 3> maMessageData;
    cGcGalaxyMapUI::NavigationStateData mNavigationStateData;
    cGcGalaxyMapUI::NavigationStateDataDisplay mNavigationStateDataDisplay;
    cGcGalacticVoxelCoordinate mMinimapLocation;
};

SKYSCRAPER_END