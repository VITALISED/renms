/**
 * @file TkRenderStateCache.h
 * @author VITALISED & Contributors
 * @since 2024-01-18
 *
 * Copyright (C) 2024  VITALISED & Contributors
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

#include <toolkit/graphics/2d/texture/vulkan/TkTextureVulkan.h>
#include <toolkit/graphics/api/TkGraphicsTypes.h>
#include <toolkit/graphics/shader/TkShader.h>
#include <toolkit/graphics/shader/TkVertexDefinition.h>

SKYSCRAPER_BEGIN

class cFrameBuffer
{
  public:
    VkImageLayout *mpColourSurfaceResourceState[14][6];
    struct VkImage_T *mColourSurface[6];
    struct VkImage_T *mColourSurfaceBuffers[6][2];
    VkImageCreateInfo mColourSurfaceCreateInfo[6];
    struct VkDeviceMemory_T *mColourMemory[6];
    void *mColourSurfaceVA_ESRAM[6];

    union {
        VkImageView_T *mColourSurfaceRTV[14][6];
        VkImageView_T *mColourSurfaceCubeRTV[6][14][6];
    };

    union {
        VkImageView_T *mColourSurfaceRTVBuffers[14][6][2];
        VkImageView_T *mColourSurfaceCubeRTVBuffers[6][14][6][2];
    };

    struct VkImageView_T *mColourSurfaceUAV[6];
    VkFormat mColourSurfaceFormat[6];
    struct VkImage_T *mDepthSurface;
    struct VkImage_T *mDepthSurfaceBuffers[2];
    VkImageCreateInfo mDepthSurfaceCreateInfo;
    struct VkDeviceMemory_T *mDepthMemory;
    struct VkImageView_T *mDepthSurfaceDSV;
    struct VkImageView_T *mDepthSurfaceDSVBuffers[2];
    struct VkImageView_T *mDepthSurfaceUAV;
    VkFormat mDepthSurfaceFormat;
    VkImageLayout *mpDepthSurfaceResourceState;
    uint8_t miActiveColourBufferCount;
    bool mbHasDepth;
    bool mbDepthUsesBackBuffer;
    bool mbHasColour;
    VkImageLayout mColourSurfaceResourceStateBuf[14][6];
    VkImageLayout mDepthSurfaceResourceStateBuf;
    const char *mpColourLastBoundPipelineStage;
    const char *mpDepthLastBoundPipelineStage;
};

class cTkRenderStateCacheSetup
{
  public:
    unsigned int mxColourMask;
    bool mbColourWriteEnable;
    unsigned int mStencilRef;
    unsigned int muPrimitiveType;
    bool mbDepthBoundsAllowed;
    bool mbDepthBoundsEnable;
    bool mbForceEarlyZ;
    int16_t miLineWidth;
    VkViewport mViewPort;
    VkRect2D mScissorRect;
    bool mbIsGLClipSpace;
};

class cTkRenderStateCache
{
  public:
    VkVertexInputBindingDescription mBindingDesc[2];
    VkVertexInputAttributeDescription mAttrDescs[20];
    uint64_t mAttrDescsHash;
    uint64_t mPsoHash;
    cTkMiniPipelineStateDescriptor mPipelineStateDesc;
    VkBuffer_T *mSetIndexBuffer;
    uint64_t mSetIndexOffset;
    VkIndexType mSetIndexType;
    cTkRenderStateCacheSetup mCurrentSetup;
    cTkRenderStateCacheSetup mLastSetup;
    const cTkShader *mpBoundShader;
    cFrameBuffer *mpBoundFrameBuffer;
    VkImage_T *mpBoundDepthTarget;
    VkImageLayout *mpBoundDepthTargetResourceState;
    VkImageView_T *mBoundDSUAVHandle;
    VkImageView_T *mBoundDSVHandle;
    VkFormat mBoundDepthFormat;
    unsigned int mBoundShaderDataSize;
    VkImageView_T *mBoundRTVHandle[6];
    VkImageView_T *mBoundSRV[24];
    VkSampler_T *mBoundSampler[24];
    VkImageLayout mBoundState[24];
    int16_t mBoundMipStatsIndex[24];
    VkImageView_T *mBoundUAV[8];
    VkBuffer_T *mBoundStorage[5];
    unsigned int mBoundOffset[5];
    unsigned int mBoundSize[5];
    cTkTexture *mpBoundColourTexture[6];
    cTkTexture *mpBoundDepthTexture;
    TkGpuAddress mBoundShaderDataGPUAddress;
    void *mBoundShaderDataCPUAddress;
    unsigned int muTargetMip;
    struct VkDescriptorSet_T *mUniformDescriptorHandle;
    struct VkPipelineLayout_T *mPipeLayout;
    TkGpuAddress mpBoundIndexData;
    cTkVertexBufferSlot maVertexBufferSlots[2];
    cTkGraphicsContext *mpTkContext;
    struct VkPipeline_T *mpPipelineState;
    bool mbUniform_Dirty;
    bool mbStorage_Dirty;
    bool mbTexture_Dirty;
    bool mbResetAll;
    cTkMatrix44 mViewMatrix;
    cTkMatrix44 mProjectionMatrix;
    cTkMatrix44 mInverseViewMatrix;
    cTkMatrix44 mInverseProjectionMatrix;
    cTkMatrix44 mViewMatrixLeft;
    cTkMatrix44 mViewMatrixRight;
};

SKYSCRAPER_END