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