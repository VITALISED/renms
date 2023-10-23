#pragma once

#include <skyscraper.h>
#include <application/states/GcApplicationState.h>

SKYSCRAPER_BEGIN

class cGcUserdataPrimaryPlanetChange
{
  ApplicationStateEvents::Enum mCheck;
  int mNewPrimaryPlanetIndex;
  bool mImmediate;
};

SKYSCRAPER_END