#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

template <typename T>
class TkSTLAllocatorShim : std::allocator<T>
{ 
    template <typename U>
    struct rebind
    {
        using other = TkSTLAllocatorShim<U>;
    };
};

SKYSCRAPER_END