#pragma once

#include <skyscraper.h>
#include <application/states/GcApplicationState.h>
#include <toolkit/system/timer/TkStopwatch.h>
#include <toolkit/maths/numeric/generic/TkMatrix34Generic.h>
#include <toolkit/graphics/2d/ui/objects/text/Tk2dText.h>
#include <toolkit/graphics/2d/ui/objects/text/Tk2dTextPreset.h>
#include <simulation/solarsystem/planet/GcUserdataPrimaryPlanetChange.h>

SKYSCRAPER_BEGIN

class cGcApplicationSimulationState : public cGcApplicationState
{
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
    cTkFixedString<128,wchar_t> macFramerateTextBuffer;
    cGcUserdataPrimaryPlanetChange mChangePlanetData;
    int miPrepareToPauseFrame;
    bool mChangePlanetRequested;
    bool mbDoMeasurement;
    bool mbPrepareToPause;
    bool mbFirstBootPrepare;
    float mfResetVRCameraTimer;
    cTkSmartResHandle mCloudsPipelineRes;
    cTkFixedString<32,wchar_t> mFramerateString;
    void *mThreadSyncStartedEvent;
    void *mCullingStartedEvent;
};

SKYSCRAPER_END