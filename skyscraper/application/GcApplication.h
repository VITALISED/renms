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
#include <toolkit/maths/numeric/TkIntTuples.h>
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
 * @class cGcApplication
 * @brief Global singleton storing most data in Game Components. Implements FSM calls
 * @details
 * Whilst this struct stores most things, you will want to use @ref cTkEngineUtils for Node calls as of right
 * now, since we dont have globals for @ref Engine objects directly.
 *
 * You can access it by calling
 * cGcApplication::GetInstance()
 *
 * @code{.cpp}
 * cGcApplication* gApplication = cGcApplication::GetInstance();
 * @endcode
 *
 */
class cGcApplication : public cTkFSM
{
  public:
    /**
     * Virtuals
     */

    virtual ~cGcApplication() final;
    virtual void Construct() final;
    virtual void Update() final;
    virtual void Destruct() final;
    virtual void StatePrepare(cTkFSMState *, const void *) final;
    virtual void StateRelease(cTkFSMState *, const void *) final;

    /**
     * Methods
     */

    void NotifyResolutionChangedCallback(const cTkIntTuple2<int, 0> &lScreenRes);
    bool DrainFileLoadsAndPollableTasks(bool lbTimeoutWithFrame);
    bool DrainFileLoadsAndPollableTasks(bool lbTimeoutWithFrame, int liLoadBalancingTimeout);
    void HideSimulationNodes();
    void ShowSimulationNodes();
    bool AllowPause();
    void ChangeAppGameMode(ePresetGameMode leMode, int liPlayerSlotIndex);
    void UpdateInputManagers(float lfTimestep);
    void VRAssertCallback(cTkAssertData &lAssertData, bool *lpbIgnoreFlag, bool *lpbBreakEnabled);
    void UpdateVRAssertMessage();
    bool IsAccessibleUIEnabled();

    /**
     * Getter/Setters
     */

    inline cGcSimulation *GetSimulation() { return &mpData->mSimulation; }
    inline cGcRealityManager *GetRealityManager() { return &mpData->mRealityManager; }
    inline cGcGameState *GetGameState() { return &mpData->mGameState; }
    inline cGcSeasonalData *GetSeasonalData() { return &mpData->mSeasonalData; }
    inline cGcHUDManager *GetHUDManager() { return &mpData->mHUDManager; }
    inline cGcFrontendManager *GetFrontendManager() { return &mpData->mFrontendManager; }
    inline cGcInWorldUIManager *GetInWorldUIManager() { return &mpData->mInWorldUIManager; }
    inline cGcCameraManager *GetCameraManager() { return &mpData->mCameraManager; }
    inline cGcGraphicsManager *GetGraphicsManager() { return &mpData->mGraphicsManager; }
    inline cTkInputManager *GetInputManager() { return mpData->mpInputManager; }
    inline cGcGalaxyMap *GetGalaxyMap() { return &mpData->mGalaxyMap; }
    inline cGcDebugEditor *GetDebugEditor() { return &mpData->mDebugEditor; }
    inline cTkDebugRenderer *GetDebugRenderer() { return &mpData->mDebugRenderer; }
    inline cGcNGuiManager *GetNGuiManager() { return &mpData->mNGuiManager; }
    inline cGcFirstBootContext *GetFirstBootContext() { return &mpData->mFirstBootContext; }
    inline cGcNetworkManager *GetNetworkManager() { return &mpData->mNetworkManager; }
    inline cGcAtlasManager *GetAtlasManager() { return &mpData->mAtlasManager; }

    /**
     * Custom implementations
     */

    /**
     * @fn cGcApplication::GetInstance
     * @brief Get the running instance of cGcApplication.
     */
    static cGcApplication *GetInstance();

    /**
     * Detail
     */

    DECLARE_METHOD_DETAIL(Update, void(cGcApplication *), "40 53 48 83 EC ? E8 ? ? ? ? 48 89 05 ? ? ? ?");

    /**
     * Members
     */

    /**
     * @brief Storage class for GcApplication.
     */
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
};

SKYSCRAPER_END