/**
 * @file EgTexture.h
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

#include <engine/source/engine/EgResource.h>
#include <toolkit/graphics/2d/texture/vulkan/TkTextureVulkan.h>

SKYSCRAPER_BEGIN

class cEgTextureResource : public cEgResource
{
    cTkColour *mpaAverageColours;
    cTkColour mAverageColour;
    int32_t miNumColours;
    eTkTextureType meTextureType;
    cTkTextureBase::eTexFormat meTextureFormat;
    uint32_t muRenderBufferObject;
    int32_t miStreamListIndex;
    bool mbEvictionForced;
    uint8_t muiHighPriorityRequested;
    int32_t miVirtualTextureIndex;
    bool mbIsSRGB;
    bool mbHasMipMaps;
    bool mbCacheUsed;
    cTkTexture mTexture;

    ~cEgTextureResource();
    int32_t GetDataSize();
    void Release();
    void InitDefault();
    bool Load(const char *, int);
    int32_t GetElementCount(int);
    int32_t GetElementParamInt(int, int, int);
    void SetElementParamInt(int, int, int, int);
    float GetElementParamFloat(int, int, int, int);
    void SetElementParamFloat(int, int, int, int, float);
    void *MapResStream(int, int, int, bool, bool, const char *);
    void UnmapStream(int);
};

SKYSCRAPER_END