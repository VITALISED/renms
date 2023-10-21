#pragma once

#include <skyscraper.h>
#include <engine/source/engine/EgScene.h>
#include <toolkit/maths/geometry/TkPhysRelMat34.h>
#include <toolkit/maths/numeric/generic/TkMatrix44Generic.h>
#include <toolkit/resources/TkSmartResHandle.h>
#include <toolkit/utilities/fsm/TkFSMState.h>

SKYSCRAPER_BEGIN

class cGcAsyncLoadOps
{
public:
    enum Operation
    {
        DrainFileIO,
        DrainShaders,
        DrainTasks,
    };
};

class cGcApplicationState : public cTkFSMState
{
    cTkPhysRelMat34 mStereoCameraMatrices[2];
    cTkPhysRelMat34 mStereoPrevCameraMatrices[2];
    cTkSmartResHandle mShadowsPipelineRes;
    cTkSmartResHandle mShadowsTextureRes;
    cTkMatrix44 mStereoViewMatrices[2];
    cTkMatrix44 maMainProjMatrixHmd[2];
    cTkMatrix44 maMainViewMatrixHmd[2];
    cTkMatrix44 maMainPrevProjMatrixHmd[2];
    cTkMatrix44 maMainPrevViewMatrixHmd[2];
    EgRenderQueueHandle mMainRenderHandle;
    cTkMatrix44 mMainProjMatrix;
    cTkMatrix44 mMainViewMatrix;
    cTkMatrix44 mMainPrevProjMatrix;
    cTkMatrix44 mMainPrevViewMatrix;
    cTkPhysRelMat34 mPrevCameraMatrix;
    cTkPhysRelMat34 mCameraMatrix;
};

SKYSCRAPER_END