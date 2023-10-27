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
#include <application/states/GcApplicationState.h>
#include <atlas/WinHttpTask.h>
#include <engine/source/engine/EgMain.h>
#include <toolkit/maths/numeric/generic/TkMatrix34Generic.h>
#include <simulation/player/GcPlayer.h>
#include <simulation/player/GcPlayerRespawn.h>

SKYSCRAPER_BEGIN

namespace LocalLoadPhase
{
    typedef WinHttpTask::State::Enum Enum;   
}

class cGcApplicationLocalLoadState : public cGcApplicationState
{
    typedef cGcPlayer::eRocketBootsDoubleTapState SaveRestoreMode;

    cGcPlayerRespawn::RespawnReason meLoadReason;
    bool mColdBoot;
    bool mbWarpingToNewGalaxy;
    bool mbWarpingUsingGalaxyMap;
    bool mbForceRespawnAsFreshStart;
    cGcApplicationLocalLoadState::SaveRestoreMode meSaveRestoreMode;
    LocalLoadPhase::Enum mPhase;
    int mPrelaunchCountdown;
    int mRepeatingPhaseCounter;
    Engine::cEgShaderCompilationState *mpShaderCompilationState;
    unsigned __int64 mLoadTimerStartSystemTime;
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