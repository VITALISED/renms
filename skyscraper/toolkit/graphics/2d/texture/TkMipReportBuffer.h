/**
 * @file TkMipReportBuffer.h
 * @author VITALISED & Contributors
 * @since 2023-12-05
 * 
 * Copyright (C) 2023  VITALISED & Contributors
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include <skyscraper.h>

#include <vulkan/vulkan.h>

SKYSCRAPER_BEGIN

struct TkMipReportBuffer
{
    struct TextureQueries
    {
        uint64_t compute_pixhit;
        int32_t count;
        uint16_t bookmarks[256][2];
    };

    VkQueryPool_T *queryheap;
    VkFence_T *fenceValue;
    VkDeviceMemory_T *memory;
    VkBuffer_T *buffer;
    uint64_t *mOutBufferMapped;
    int32_t miNumQueries;
    TkMipReportBuffer::TextureQueries per_texture[257];
};

SKYSCRAPER_END