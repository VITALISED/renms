#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

template <typename T>
class cTkRefCntContainer
{
    T *mPtr;
    std::atomic<int> mRef;
};

template <typename T>
class cTkSharedPtr
{
    cTkRefCntContainer<T> *mRefCntr;
};

SKYSCRAPER_END