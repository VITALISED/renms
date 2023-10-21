#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

class cTkTextureBase
{
    eTkTextureType meType;
    cTkTextureBase::eTexFormat meFormat;
    eTextureAddressMode meTextureAddressMode;
    eTextureFilterMode meTextureFilterMode;
    eTkTextureReductionMode meTextureReductionMode;
    bool mbIsSRGB;
    bool mbIsShadowMap;
    int miWidth;
    int miHeight;
    int miDepth;
    __int16 miNumMips;
    __int16 miAnisotropy;
    int miDataSize;
    int miMemorySize;
    __int16 miMipStatsCounterIndex[4];
    int miFinestResidentPixelCount;
    int miFinestMipVisible;
    int miNumClampedPixels;
    int miLastFetchedFrame;
    int miFileStartOffset;
    const cTkTextureStreamFuncs *mpStreamFuncs;
    void *mStreamFuncContext;
    int miMipZeroSize;
    int miEvictedSize;
    __int16 miEvictableMips;
    __int16 miEvictedMips;
    bool mbAllocatedFromStreamingStore;
    bool mbAllocatedWithMipBias;
    unsigned __int8 miEvictionCountdown;
};

SKYSCRAPER_END