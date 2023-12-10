/**
 * @file GcApplication.h
 * @author VITALISED & Contributors
 * @since 2023-12-05
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

#include <application/GcFirstBootContext.h>
#include <application/GcGameConfigCache.h>
#include <application/states/GcApplicationAmbientGameState.h>
#include <application/states/GcApplicationBootState.h>
#include <application/states/GcApplicationCoreServicesState.h>
#include <application/states/GcApplicationDeathState.h>
#include <application/states/GcApplicationGalacticMapState.h>
#include <application/states/GcApplicationGameModeSelectorState.h>
#include <application/states/GcApplicationGlobalLoadState.h>
#include <application/states/GcApplicationLocalLoadState.h>
#include <application/states/GcApplicationScratchpadState.h>
#include <application/states/GcApplicationShutdownState.h>
#include <application/states/GcApplicationSimulationState.h>
#include <application/states/GcApplicationSmokeTestState.h>
#include <application/states/GcApplicationTitleScreenState.h>
#include <application/states/GcApplicationUGCBaseViewerState.h>
#include <atlas/GcAtlasManager.h>
#include <audio/GcAudioManager.h>
#include <gamestate/GcGameAnalytics.h>
#include <gamestate/GcGameState.h>
#include <gamestate/GcSeasonalData.h>
#include <graphics/GcFrontendManager.h>
#include <graphics/GcGraphicsManager.h>
#include <graphics/GcHUDManager.h>
#include <graphics/GcInWorldUIManager.h>
#include <graphics/camera/GcCameraManager.h>
#include <graphics/ngui/GcNGuiManager.h>
#include <networking/GcNetworkManager.h>
#include <online/activities/GcActivitiesTracker.h>
#include <reality/GcRealityManager.h>
#include <resources/GcResourceManager.h>
#include <simulation/GcSimulation.h>
#include <simulation/galaxy/GcGalaxyMap.h>
#include <system/input/GcInput.h>
#include <system/input/GcVibrationManager.h>
#include <toolkit/graphics/debug/TkDebugRenderer.h>
#include <toolkit/maths/utilities/spatial/TkSampleDistribution.h>
#include <toolkit/system/TkCSMutex.h>
#include <toolkit/system/input/TkInputManager.h>
#include <toolkit/system/timer/TkStopwatch.h>
#include <toolkit/system/timer/TkTimeManager.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/utilities/fsm/TkFSM.h>
#include <toolkit/utilities/string/TkString.h>
#include <utilities/debug/GcDebugEditor.h>

#include <gamestate/gcgamemode.meta.h>

SKYSCRAPER_BEGIN

/**
 * A singleton managing most of the game's heap allocated structures and other classes.
 */
class cGcApplication : public cTkFSM
{
  public:
    struct ALIGN(16) Data
    {
        cGcFirstBootContext mFirstBootContext;
        cTkMcQmcLFSRStore mTkMcQmcLFSRStore;
        cGcRealityManager mRealityManager;
        cGcGameState mGameState;
        cGcSeasonalData mSeasonalData;
        cGcSimulation mSimulation;
        cGcHUDManager mHUDManager;
        cGcFrontendManager mFrontendManager;
        cGcInWorldUIManager mInWorldUIManager;
        cGcCameraManager mCameraManager;
        cGcGraphicsManager mGraphicsManager;
        cTkInputManager *mpInputManager;
        cGcInputRemap mInputRemap; // stub
        cGcVibrationManager mVibrationManager;
        cTkTimeManager mTimeManager;
        cTkDebugRenderer mDebugRenderer; // stub
        cGcDebugEditor mDebugEditor;     // stub
        cGcNGuiManager mNGuiManager;     // stub
        cGcAudioManager mAudioManager;   // stub
        cGcAtlasManager mAtlasManager;
        cGcNetworkManager mNetworkManager;
        cGcResourceManager mResourceManager;
        cGcGalaxyMap mGalaxyMap;
        cGcGameAnalytics mGameAnalytics;
        cGcActivitiesTracker mActivitiesTracker;
    };

    cGcApplication::Data *mpData;
    uint32_t muPlayerSaveSlot;
    ePresetGameMode meGameMode;
    ePresetGameMode meSeasonalGameMode;
    bool mbSavingEnabled;
    bool mbFullyBooted;
    cGcGameConfigCache mGameConfigCache;
    cTkStopwatch mRenderTimer;
    long double mLastRenderTimeMS;
    long double mfStartTime;
    int32_t miLoadBalancingTimeout;
    cGcApplicationBootState mApplicationBootState;
    cGcApplicationCoreServicesState mApplicationCoreServicesState;
    cGcApplicationGlobalLoadState mApplicationGlobalLoadState;
    cGcApplicationLocalLoadState mApplicationLocalLoadState;
    cGcApplicationSimulationState mApplicationSimulationState;
    cGcApplicationShutdownState mApplicationShutdownState;
    cGcApplicationGalacticMapState mApplicationGalacticMapState;
    cGcApplicationSmokeTestState mApplicationSmokeTestState;
    cGcApplicationAmbientGameState mApplicationAmbientGameState;
    cGcApplicationDeathState mApplicationDeathState;
    cGcApplicationScratchpadState mApplicationScratchpadState;
    cGcApplicationGameModeSelectorState mApplicationGameModeSelectorState;
    cGcApplicationTitleScreenState mApplicationTitleScreenState;
    cGcApplicationUGCBaseViewerState mApplicationUGCBaseViewerState;
    float mfResetVRCameraTimer;
    bool mbPaused;
    bool mbTkPaused;
    bool mbStepOneFrame;
    bool mbMultiplayerActive;
    bool mbWindowFocused;
    bool mbHasFocus;
    bool mbQuitRequested;
    bool mResumeFromSuspendSave;
    cTkVector<cTkFixedString<128, char>> mAssertMessage;
    cTkCSMutex mAssertMessageLock;

    ~cGcApplication();
    void Construct();
    void Update();
    void Destruct();
    void StatePrepare(cTkFSMState *, const void *);
    void StateRelease(cTkFSMState *, const void *);
};

SKYSCRAPER_END