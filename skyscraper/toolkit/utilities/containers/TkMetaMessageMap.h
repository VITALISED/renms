#pragma once

#include <skyscraper.h>
#include <toolkit/utilities/containers/TkStackVector.h>

SKYSCRAPER_BEGIN

template <int I>
class cTkMetaMessageMap
{
    robin_hood::detail::Table<false, 80, unsigned __int64, cTkStackVector<std::function<void __cdecl(cTkMetaMessageWrapperTemplated<void> const &)>, I>,robin_hood::hash<unsigned __int64,void>,std::equal_to<unsigned __int64> > mSubscriptionMap;
};

SKYSCRAPER_END