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