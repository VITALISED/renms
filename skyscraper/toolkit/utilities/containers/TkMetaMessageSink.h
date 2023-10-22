#pragma once

#include <skyscraper.h>
#include <toolkit/utilities/containers/TkMetaMessageMap.h>

SKYSCRAPER_BEGIN

template <typename T>
class cTkMetaMessageSink
{
    cTkMetaMessageMap<2> mMetaMessageSubscriptions;
    T mData;
    bool mbConstructed;
};

SKYSCRAPER_END