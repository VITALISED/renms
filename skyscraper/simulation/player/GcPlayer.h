#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

class cGcPlayer
{
public:
    enum eRocketBootsDoubleTapState
    {
        None,
        WaitingForRelease,
        WaitingForSecondTap,
        SingleTap,
        FEEDBACK_PEN_DOUBLETAP,
    };
};

SKYSCRAPER_END