#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

struct TkMipReportBuffer
{
    struct TextureQueries
    {
        unsigned __int64 compute_pixhit;
        int count;
        unsigned __int16 bookmarks[256][2];
    };

    struct VkQueryPool_T *queryheap;
    struct VkFence_T *fenceValue;
    struct VkDeviceMemory_T *memory;
    struct VkBuffer_T *buffer;
    unsigned __int64 *mOutBufferMapped;
    int miNumQueries;
    TkMipReportBuffer::TextureQueries per_texture[257];
};

SKYSCRAPER_END