#pragma once

#include <skyscraper.h>
#include <toolkit/system/TkCSMutex.h>
#include <toolkit/system/timer/TkStopwatch.h>
#include <toolkit/utilities/fsm/TkFSM.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/utilities/TkString.h>
#include <metadata/gamestate/gcgamemode.meta.h>
#include <application/GcGameConfigCache.h>

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

SKYSCRAPER_BEGIN

class cGcApplication : public cTkFSM
{
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
    cTkVector<cTkFixedString<128,char> > mAssertMessage;
    cTkCSMutex mAssertMessageLock;
};

SKYSCRAPER_END