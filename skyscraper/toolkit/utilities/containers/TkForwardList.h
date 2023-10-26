#pragma once

#include <skyscraper.h>
#include <toolkit/system/TkMemoryManager.h>

SKYSCRAPER_BEGIN

template <typename T>
class cTkForwardList : public std::forward_list<T, TkSTLAllocatorShim<T> >
{ };

SKYSCRAPER_END