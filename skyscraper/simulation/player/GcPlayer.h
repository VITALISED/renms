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
        DoubleTap,
    };
};

SKYSCRAPER_END