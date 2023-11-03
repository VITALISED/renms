/*
    Copyright (C) 2023  VITALISED, tractorbeam

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

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