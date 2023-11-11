#pragma once

#include <skyscraper.h>

#include <toolkit/system/memory/TkMemoryManager.h>

#include <deque>

SKYSCRAPER_BEGIN

template <typename T>
class cTkDeque : public std::deque<T, TkSTLAllocatorShim<T>>
{
}

SKYSCRAPER_END