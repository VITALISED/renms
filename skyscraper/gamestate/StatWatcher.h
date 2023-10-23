#pragma once

#include <skyscraper.h>
#include <toolkit/data/TkMetaData.h>

SKYSCRAPER_BEGIN

class IStatWatcher
{
    virtual void StatChanged(const TkID<128> *, long double);
    virtual void StatChanged(const TkID<128> *, __int64);
};

SKYSCRAPER_END