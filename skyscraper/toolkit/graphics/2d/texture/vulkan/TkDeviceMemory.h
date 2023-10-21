#pragma once

#include <skyscraper.h>
#include <vk_mem_alloc.h>

SKYSCRAPER_BEGIN

struct TkDeviceMemory
{
    VmaAllocation_T *mAlloc;
    struct VkDeviceMemory_T *mMemory;
    unsigned __int64 mOffset;
};

SKYSCRAPER_END