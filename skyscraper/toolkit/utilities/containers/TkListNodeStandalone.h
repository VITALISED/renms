#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

template <typename T>
class cTkListNode
{
    cTkListNode<T> *mpNext;
    cTkListNode<T> *mpPrev;
    T *mValue;
};

SKYSCRAPER_END