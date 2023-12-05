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
#include <reality/GcRealityManager.h>
#include <system/input/GcVibrationManager.h>
#include <toolkit/maths/utilities/spatial/TkSampleDistribution.h>
#include <toolkit/system/TkCSMutex.h>
#include <toolkit/system/timer/TkStopwatch.h>
#include <toolkit/system/timer/TkTimeManager.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/utilities/fsm/TkFSM.h>
#include <toolkit/utilities/string/TkString.h>

#include <gamestate/gcgamemode.meta.h>

SKYSCRAPER_BEGIN

/**
 * A singleton managing most of the game's heap allocated structures and other singletons.
 */
class cGcApplication : public cTkFSM
{
  public:
    struct ALIGN(16) Data
    {
        cGcFirstBootContext mFirstBootContext;
        cTkMcQmcLFSRStore mTkMcQmcLFSRStore;
        cGcRealityManager mRealityManager;
        /*cGcGameState*/ char mGameState[0x43C560];
        /*cGcSeasonalData*/ char mSeasonalData[0x69F0];
        /*cGcSimulation*/ char mSimulation[0x25F7C0];
        /*cGcHUDManager*/ char mHUDManager[0x145270];
        /*cGcFrontendManager*/ char mFrontendManager[0x81E00];
        /*cGcInWorldUIManager*/ char mInWorldUIManager[0x4A320];
        /*cGcCameraManager*/ char mCameraManager[0x2B60];
        /*cGcGraphicsManager*/ char mGraphicsManager[0x1603E0];
        /*cTkInputManager*/ char *mpInputManager[0x1C80];
        /*cGcInputRemap*/ char mInputRemap[0x950];
        cGcVibrationManager mVibrationManager;
        cTkTimeManager mTimeManager;
        /*cTkDebugRenderer*/ char mDebugRenderer[0x108];
        /*cGcDebugEditor*/ char mDebugEditor[0x9B0];
        /*cGcNGuiManager*/ char mNGuiManager[0x768];
        /*cGcAudioManager*/ char mAudioManager[0xB90];
        cGcAtlasManager mAtlasManager;
        /*cGcNetworkManager*/ char mNetworkManager[0x21AB0];
        /*cGcResourceManager*/ char mResourceManager[0x170];
        /*cGcGalaxyMap*/ char mGalaxyMap[0x18];
        /*cGcGameAnalytics*/ char mGameAnalytics[0x1F0];
        /*cGcActivitiesTracker*/ char mActivitiesTracker[0x50];
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