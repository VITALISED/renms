#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

template<int Iter>
struct TkIterationState
{
    std::array<unsigned __int64, Iter> muIndices;
    std::array<bool, Iter> mbInnerStates;
};

SKYSCRAPER_END