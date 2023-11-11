#pragma once

#include <skyscraper.h>

#include <toolkit/utilities/containers/TkClassPool.h>

SKYSCRAPER_BEGIN

template <typename T, int liAmount>
class cGcEffectList
{
    cTkClassPool<T, liAmount> maEffects;
    int miNumber;
};

SKYSCRAPER_END