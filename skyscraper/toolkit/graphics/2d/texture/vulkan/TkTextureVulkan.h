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

#include <toolkit/graphics/2d/texture/TkTextureBase.h>
#include <toolkit/graphics/2d/texture/vulkan/TkDeviceMemory.h>

SKYSCRAPER_BEGIN

class cTkTexture : public cTkTextureBase
{
    void *mpTextureData;
    VkImage_T *mTexture;
    VkImageCreateInfo mImageDesc;
    TkDeviceMemory mTextureMemory;
    VkImageView_T *maTextureSrvMips[14];
    VkImageLayout maResourceState[14];
    bool mbDepthOnly;
    VkImageView_T *muTextureSrv;
    VkImageView_T *muTextureUav;
    VkSampler_T *muSampler;
    float mfLodClamp;
    uint16_t *mMapping;
    uint16_t mEvictableMipPageCount[16];
    uint16_t mMipStartPage[16];
    uint64_t mTailOffset;
    uint64_t mTailArrayStride;
    uint16_t miUltraMips;
    uint16_t miDetailableMips;
    float mfLodBias;
    int32_t miNumPages;
    int32_t miEvictedPages;
    int16_t miMipZeroPages;
    int16_t miMipZeroUnusedPages;
    bool mbIsPartiallyResident;
};

SKYSCRAPER_END