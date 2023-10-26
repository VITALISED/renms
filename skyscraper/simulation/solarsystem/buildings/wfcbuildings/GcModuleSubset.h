#pragma once

#include <skyscraper.h>
#include <toolkit/utilities/TkArray.h>

SKYSCRAPER_BEGIN

class cGcModuleSet;

class cGcModuleSubset
{
    const cGcModuleSet *mDomain;
    cTkBitArray<unsigned __int64, 512> mData;
};

SKYSCRAPER_END