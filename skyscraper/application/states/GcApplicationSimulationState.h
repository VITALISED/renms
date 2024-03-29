/**
 * @file GcApplicationSimulationState.h
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

#include <application/states/GcApplicationState.h>
#include <toolkit/graphics/2d/ui/objects/text/Tk2dText.h>
#include <toolkit/graphics/2d/ui/objects/text/Tk2dTextPreset.h>
#include <toolkit/maths/numeric/generic/TkMatrix34Generic.h>
#include <toolkit/system/timer/TkStopwatch.h>

SKYSCRAPER_BEGIN

class cGcUserdataPrimaryPlanetChange
{
  public:
    ApplicationStateEvents::Enum mCheck;
    int mNewPrimaryPlanetIndex;
    bool mImmediate;
};

class cGcApplicationSimulationState : public cGcApplicationState
{
  public:
    cTkStopwatch mSimThreadTimer;
    cTkStopwatch mSimUpdateTimer;
    cTkStopwatch mSyncPointTimer;
    float mfLastSimThreadTimeCPU;
    float mfLastSimUpdateTimeCPU;
    float mfLastSyncPointTimeCPU;
    cTkMatrix34 mMeasurementAnchorTM;
    cTkMatrix44 mDebugProjMatrix;
    cTkMatrix44 mDebugViewMatrix;
    cTkVector3 mvDebugRenderOffset;
    bool mbFirstRender;
    void *mRenderMutex;
    std::atomic<bool> mbRunUpdateThread;
    std::atomic<bool> mbExitUpdateThread;
    std::atomic<bool> mbUpdateThreadActive;
    unsigned int mThreadId;
    bool mbUpdateThreadCreated;
    bool mbUpdate;
    bool mbRender;
    float mfFoVAdjust;
    float mfFovSpringSpeed;
    float mfFoV;
    float mfPrevFoV;
    float mfFoVFixedDist;
    float mfTimestep;
    cTk2dText mFramerateText;
    cTk2dTextPreset mTextPreset;
    cTkFixedString<128, wchar_t> macFramerateTextBuffer;
    cGcUserdataPrimaryPlanetChange mChangePlanetData;
    int miPrepareToPauseFrame;
    bool mChangePlanetRequested;
    bool mbDoMeasurement;
    bool mbPrepareToPause;
    bool mbFirstBootPrepare;
    float mfResetVRCameraTimer;
    cTkSmartResHandle mCloudsPipelineRes;
    cTkFixedString<32, wchar_t> mFramerateString;
    void *mThreadSyncStartedEvent;
    void *mCullingStartedEvent;

    cGcApplicationSimulationState();

    virtual void Construct();
    virtual void Prepare(cTkFSMState *, const void *);
    virtual void Release(cTkFSMState *, const void *);
    virtual void Destruct();
    virtual void Render(EgRenderParity::List);
    virtual bool SupportsEvenOddRendering();
    virtual void ThreadedUpdate();
    virtual bool ThreadSyncPoint();
    virtual void BuildRenderQueue();

    void DoThreadedUpdate(void *lpData);
};

SKYSCRAPER_END