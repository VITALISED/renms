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