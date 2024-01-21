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
  public:
    virtual ~cEgTextureResource();
    virtual int32_t GetDataSize();
    virtual void Release();
    virtual void InitDefault();
    virtual bool Load(const char *, int);
    virtual int32_t GetElementCount(int);
    virtual int32_t GetElementParamInt(int, int, int);
    virtual void SetElementParamInt(int, int, int, int);
    virtual float GetElementParamFloat(int, int, int, int);
    virtual void SetElementParamFloat(int, int, int, int, float);
    virtual void *MapResStream(int, int, int, bool, bool, const char *);
    virtual void UnmapStream(int);

    bool AbortEviction();
    void AddToStreamList();
    void CalculateAverageColour(uint8_t *lpu8PixelDataIn, int liWidth, int liHeight, int liFlags);
    void CopyResourceFlagsToTexture();
    void Evict();
    void EvictOneMip();
    int GetMipCount();
    void Initialise(uint32_t liWidth, uint32_t liHeight, uint32_t, int lxFlags, bool lbCanUseDCC);
    bool LoadFromDds(
        const char *lpcHeader, const char *lpPixelData, int liStartMip, int liSkippedSize, int liPixelDataSize,
        uint32_t *lpPackedAverageColor, int liSelectMip, int liSelectMipCount);
    void NotifyResidentToMip(int liMip, bool);
    void OutOfMemoryCallback(int64_t liNeededSize);
    void PanicEvict(int64_t liNeededSize);
    bool RequestStream(
        TkStrongType<int, TkStrongTypeIDs::TkResHandleID> lTexHandle, int liPixelCount, int liMipStatsIndex,
        int liFeedbackBufferIndex, int liStartAtMip);
    void ScheduleForEviction();
    void SearchCache();

    static void CheckForDeletedStreamingTextures();
    static cEgTextureResource *FactoryFunc(
        const std::string &lsName, int liFlags, cTkResourceDescriptor *lpResourceDescriptor);
    static void InitialisationFunc();
    static void UpdateStreaming(
        TkMipReportBuffer *lpBuffer, int *lpComputeBuffer, int liCurBufferIndex, int liNextBufferIndex);

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
};

SKYSCRAPER_END