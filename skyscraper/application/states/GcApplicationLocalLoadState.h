/**
 * @file GcApplicationLocalLoadState.h
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

#include <application/states/GcApplicationBaseLoadingState.h>
#include <engine/source/engine/EgMain.h>
#include <simulation/player/GcPlayerRespawn.h>
#include <toolkit/maths/numeric/generic/TkMatrix34Generic.h>

SKYSCRAPER_BEGIN

struct LocalLoadPhase
{
    enum Enum
    {
        ShutdownSimulation,
        EngineCleanUp,
        PreCreateSimulation,
        CreateSimulation,
        ShaderCompileDrain,
        Prelaunch,
        WaitForGeneration,
        EnsureBootPhaseCompletion,
        Spawn,
        SpawnPauseForPlayerToEnterShip,
        SpawnPauseForPlanetResourceLoading,
        PrepareHUD,
        SpawnPauseForLocalGeneration,
        WaitOnTransitionIfActive,
        StartGalaxyMapSync,
        WaitOnGalaxyMapSync,
        WaitOnNPCSpawning,
        WaitForSpaceBattleSpawn,
        OptionalPreLaunch,
        Launch,
        __EnumTerminator,
        Unspecified,
    };
};

class cGcApplicationLocalLoadState : public cGcApplicationBaseLoadingState
{
  public:
    virtual void Construct();
    virtual void Prepare(cTkFSMState *, const void *);
    virtual void Update(float);
    virtual void Event(unsigned int, const void *);
    virtual void Release(cTkFSMState *, const void *);
    virtual void Destruct();
    virtual void Render(EgRenderParity::List);

    cGcPlayerRespawn::RespawnReason GetRespawnReason();

    enum SaveRestoreMode : uint8_t
    {
        None,
        RestoringFromOptionsUI,
        LoadOrResetFromSelectorUI,
    };

    cGcPlayerRespawn::RespawnReason meLoadReason;
    bool mColdBoot;
    bool mbWarpingToNewGalaxy;
    bool mbWarpingUsingGalaxyMap;
    bool mbForceRespawnAsFreshStart;
    cGcApplicationLocalLoadState::SaveRestoreMode meSaveRestoreMode;
    LocalLoadPhase::Enum mPhase;
    int32_t mPrelaunchCountdown;
    int32_t mRepeatingPhaseCounter;
    Engine::cEgShaderCompilationState *mpShaderCompilationState;
    uint64_t mLoadTimerStartSystemTime;
    cTkMatrix34 mSavedCameraMatrix;
    cTkPhysRelMat34 mLastFrameCameraMatrix;
    cTkVector3 mRenderOffset;
    float mfLastFrameFov;
    float mfSavedFoV;
    float mfSavedFoVAdj;
    float mfSavedFoVAdjDist;
    float mfShaderLoadDisplayMsg;
};

SKYSCRAPER_END