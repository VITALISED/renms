#pragma once

#include <skyscraper.h>
#include <application/states/GcApplicationState.h>
#include <atlas/WinHttpTask.h>

SKYSCRAPER_BEGIN

namespace GlobalLoadPhase
{
    typedef WinHttpTask::State::Enum Enum;
}

class cGcApplicationGlobalLoadState : public cGcApplicationState
{
    cGcAsyncLoadOps mAsyncLoadOps;
    GlobalLoadPhase::Enum mPhase;
};

SKYSCRAPER_END