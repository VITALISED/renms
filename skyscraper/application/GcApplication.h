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

// general types
#include <application/GcGameConfigCache.h>
#include <skyscraper.h>
#include <toolkit/maths/utilities/spatial/TkSampleDistribution.h>
#include <toolkit/system/TkCSMutex.h>
#include <toolkit/system/timer/TkStopwatch.h>
#include <toolkit/utilities/TkString.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/utilities/fsm/TkFSM.h>

// metadata
#include <metadata/source/gamestate/gcgamemode.meta.h>

// states
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

// managers
#include <reality/GcRealityManager.h>

// other
#include <application/GcFirstBootContext.h>
#include <gamestate/GcGameState.h>
#include <simulation/GcSimulation.h>

SKYSCRAPER_BEGIN

class cGcApplication : public cTkFSM
{
    VFT<5> *__vftable;

    struct Data
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
        cGcInputRemap mInputRemap;
        cGcVibrationManager mVibrationManager;
        cTkTimeManager mTimeManager;
        cTkDebugRenderer mDebugRenderer;
        cGcDebugEditor mDebugEditor;
        cGcNGuiManager mNGuiManager;
        cGcAudioManager mAudioManager;
        cGcAtlasManager mAtlasManager;
        cGcNetworkManager mNetworkManager;
        cGcResourceManager mResourceManager;
        cGcGalaxyMap mGalaxyMap;
        cGcGameAnalytics mGameAnalytics;
        cGcActivitiesTracker mActivitiesTracker;
    };

    cGcApplication::Data *mpData;
    unsigned int muPlayerSaveSlot;
    ePresetGameMode meGameMode;
    ePresetGameMode meSeasonalGameMode;
    bool mbSavingEnabled;
    bool mbFullyBooted;
    cGcGameConfigCache mGameConfigCache;
    cTkStopwatch mRenderTimer;
    long double mLastRenderTimeMS;
    long double mfStartTime;
    int miLoadBalancingTimeout;
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
};

SKYSCRAPER_END