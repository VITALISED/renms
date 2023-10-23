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