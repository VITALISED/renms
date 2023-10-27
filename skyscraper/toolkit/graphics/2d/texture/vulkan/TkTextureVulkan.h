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
    struct VkImage_T *mTexture;
    VkImageCreateInfo mImageDesc;
    TkDeviceMemory mTextureMemory;
    struct VkImageView_T *maTextureSrvMips[14];
    VkImageLayout maResourceState[14];
    bool mbDepthOnly;
    struct VkImageView_T *muTextureSrv;
    struct VkImageView_T *muTextureUav;
    struct VkSampler_T *muSampler;
    float mfLodClamp;
    unsigned __int16 *mMapping;
    unsigned __int16 mEvictableMipPageCount[16];
    unsigned __int16 mMipStartPage[16];
    unsigned __int64 mTailOffset;
    unsigned __int64 mTailArrayStride;
    unsigned __int16 miUltraMips;
    unsigned __int16 miDetailableMips;
    float mfLodBias;
    int miNumPages;
    int miEvictedPages;
    __int16 miMipZeroPages;
    __int16 miMipZeroUnusedPages;
    bool mbIsPartiallyResident;
};

SKYSCRAPER_END