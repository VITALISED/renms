#pragma once

#include <skyscraper.h>
#include <reality/GcMarkovAssembler.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/data/TkMetaData.h>

SKYSCRAPER_BEGIN

class cGcNameGenerator
{
    cTkVector<TkID<256> > maSectorLocIDs[12];
    cGcMarkovAssembler mMarkovAssembler;
};

SKYSCRAPER_END