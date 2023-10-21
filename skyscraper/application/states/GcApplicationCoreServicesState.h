#pragma once

#include <skyscraper.h>
#include <application/states/GcApplicationState.h>
#include <atlas/WinHttpTask.h>

SKYSCRAPER_BEGIN

namespace CoreSrvLoadPhase
{
    typedef WinHttpTask::State::Enum Enum;
};

class cGcApplicationCoreServicesState : public cGcApplicationState
{
    CoreSrvLoadPhase::Enum mPhase;
};

SKYSCRAPER_END