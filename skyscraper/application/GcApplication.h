#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

class cGcApplication : public cTkFSM
{
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
    std::vector<cTkFixedString<128,char>,TkSTLAllocatorShim<cTkFixedString<128,char>,1,-1> > mAssertMessage;
    cTkCSMutex mAssertMessageLock;
};

SKYSCRAPER_END