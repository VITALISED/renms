#pragma once

#include <skyscraper.h>
#include <toolkit/system/TkMemoryManager.h>

SKYSCRAPER_BEGIN

template <class Key, class T, class Hash = std::hash<Key>, class KeyEqual = std::equal_to<Key>, class Allocator = TkSTLAllocatorShim<std::pair<const Key, T> > >
class cTkUnorderedMap : public std::unordered_map<T, TkSTLAllocatorShim<T>>
{ };

struct TkIDUnorderedMap::Hash256
{
};


namespace TkIDUnorderedMap
{
    struct Hash128
    { };

    struct Hash256
    { };
}

SKYSCRAPER_END