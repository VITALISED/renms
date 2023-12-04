#pragma once

#include <skyscraper.h>

#include <reality/GcMarkovAssembler.h>
#include <toolkit/core/types/TkID.h>
#include <toolkit/utilities/containers/TkVector.h>

SKYSCRAPER_BEGIN

class cGcNameGenerator
{
  public:
    cTkVector<TkID<256>> maSectorLocIDs[12];
    cGcMarkovAssembler mMarkovAssembler;
};

SKYSCRAPER_END