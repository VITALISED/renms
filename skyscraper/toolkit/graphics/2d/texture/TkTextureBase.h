/**
 * @file TkTextureBase.h
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

#include <toolkit/graphics/2d/texture/TkTextureStreamFuncs.h>

#include <toolkit/scene/materials/tkmaterialsampler.meta.h>

SKYSCRAPER_BEGIN

enum eTkTextureType
{
    ETextureType_2D,
    ETextureType_3D,
    ETextureType_CubeMap,
    ETextureType_Array,
    ETextureType_Num,
};

enum eTkTextureReductionMode
{
    ETextureReductionMode_Average,
    ETextureReductionMode_Min,
    ETextureReductionMode_Max,
    ETextureReductionMode_Num,
};

class cTkTextureBase
{
  public:
    enum eTexFormat
    {
        Unknown,
        RGB8,
        RGBX8,
        RGBA8,
        BGRX8,
        BGRA8,
        BGR8,
        RGBA16,
        RGBA16F,
        RGBA32F,
        RGBA32UI,
        RED8,
        RED16,
        RED32F,
        RED16F,
        RG8,
        RG16,
        RG16F,
        RGB10A2,
        R11FG11FB10F,
        R32FG32F,
        RG32UI,
        DEPTH,
        DEPTH16,
        DEPTH24,
        sRGBA8,
        LinearRGBA,
        RED32I,
        RED32UI,
        RGBA16UI,
        RED8I,
        RED8UI,
        RED16_Snorm,
        BC4_Unorm,
        BC5_Snorm,
        BC5_Unorm,
        BC7,
        DXT1,
        DXT3,
        DXT5,
        DXT5_NS,
        ASTC4x4,
        ASTC5x5,
        ASTC6x6,
        ASTC8x8,
    };

    eTkTextureType meType;
    cTkTextureBase::eTexFormat meFormat;
    eTextureAddressMode meTextureAddressMode;
    eTextureFilterMode meTextureFilterMode;
    eTkTextureReductionMode meTextureReductionMode;
    bool mbIsSRGB;
    bool mbIsShadowMap;
    int32_t miWidth;
    int32_t miHeight;
    int32_t miDepth;
    int16_t miNumMips;
    int16_t miAnisotropy;
    int32_t miDataSize;
    int32_t miMemorySize;
    int16_t miMipStatsCounterIndex[4];
    int32_t miFinestResidentPixelCount;
    int32_t miFinestMipVisible;
    int32_t miNumClampedPixels;
    int32_t miLastFetchedFrame;
    int32_t miFileStartOffset;
    const cTkTextureStreamFuncs *mpStreamFuncs;
    void *mStreamFuncContext;
    int32_t miMipZeroSize;
    int32_t miEvictedSize;
    int16_t miEvictableMips;
    int16_t miEvictedMips;
    bool mbAllocatedFromStreamingStore;
    bool mbAllocatedWithMipBias;
    uint8_t miEvictionCountdown;
};

SKYSCRAPER_END