#pragma once

#include <skyscraper.h>
#include <toolkit/graphics/2d/texture/vulkan/TkTextureVulkan.h>
#include <toolkit/resources/TkSmartResHandle.h>
#include <toolkit/utilities/TkString.h>
#include <toolkit/utilities/fsm/TkFSMState.h>

SKYSCRAPER_BEGIN

class cGcSmokeTestScenario
{
    std::atomic<bool> mbIsTakingScreenshot;
    float mfPreambleLength;
    float mfScenarioLength;
    float mfCurrentTime;
    cTkFixedString<256,char> mScreenshotName;
    cTkSmartResHandle mPipelineRes;
    cTkSmartResHandle mScreenshotRenderTarget;
    cTkTexture *mpBackBufferTexture;
    bool mbIsPlayerPlaced;

    virtual void Construct();
    virtual void Prepare(cTkFSMState *, const void *);
    virtual void Update(cGcSmokeTestScenario *);
    virtual void Update();
    virtual void Render(const cGcSmokeTestScenario *);
    virtual void Reset();
    virtual bool IsCompleted();
    virtual bool IsConstantInitialStartingPositionRequired();
    virtual void PrintCycleStatus(int, int);
    virtual void WriteStatistics();
    virtual void FormatLogData(cTkFixedString<1024,char> *);
    virtual float GetPowerUsageEstimateAvgCPU();
    virtual float GetPowerUsageEstimateAvgGPU();
    virtual float GetPowerUsageEstimateAvgMEM();
    virtual float GetPowerUsageEstimateAvgOther();
};

SKYSCRAPER_END