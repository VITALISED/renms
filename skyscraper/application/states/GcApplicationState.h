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

namespace ApplicationStateEvents
{
typedef WinHttpTask::State::Enum Enum;
}

class cGcApplicationState : public cTkFSMState
{
    VFT<8> *__vftable;
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