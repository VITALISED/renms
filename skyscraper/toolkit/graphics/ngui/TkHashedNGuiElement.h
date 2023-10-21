#pragma once

#include <skyscraper.h>
#include <toolkit/data/TkMetaData.h>

SKYSCRAPER_BEGIN

class cTkHashedNGuiElement
{
    TkID<128> mID;
    unsigned __int64 mHash;
};

SKYSCRAPER_END