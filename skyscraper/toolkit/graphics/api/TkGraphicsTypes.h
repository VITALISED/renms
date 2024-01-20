/**
 * @file TkGraphicsTypes.h
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

#include <toolkit/graphics/2d/texture/TkGnmxContext.h>
#include <vulkan/vulkan.h>

SKYSCRAPER_BEGIN

enum eTkCheckerboard : uint8_t
{
    ECheckerboard_Disabled,
    ECheckerboard_Even,
    ECheckerboard_Odd,
};

enum eTkSamplingRate : uint8_t
{
    ESamplingRate_PerPixel,
    ESamplingRate_PerSample,
};

class TkGpuAddress
{
  public:
    VkBuffer_T *mBuffer;
    uint64_t mOffset;
};

class cTkMiniPipelineStateDescriptor
{
  public:
    VkShaderModule_T *mpShaderModules[6];
    VkPipelineLayout_T *mPipeLayout;
    VkRenderPass_T *mRenderPass;
    uint8_t mAttachmentCount;
    uint8_t mShaderStageCount;
    uint8_t mShaderStageBit[6];
    uint8_t mVertexBindingDescriptionCount;
    uint8_t mVertexAttributeDescriptionCount;
    uint8_t mTessPatchControlPoints;
    VkPrimitiveTopology mTopology;
    unsigned int mCullMode;
    VkFrontFace mFrontFace;
    VkPolygonMode mFillMode;
    eTkCheckerboard meCheckerboard;
    eTkSamplingRate meSamplingRate;
    VkPipelineDepthStencilStateCreateInfo mDepthStencilCreateInfo;
    unsigned int muColourMask;
    VkPipelineColorBlendAttachmentState mColorBlendAttachment;
};

class cTkGraphicsContext
{
  public:
    unsigned int mTextureQueryRefCnt;
    unsigned int mTextureQueryIndex;
    uint16_t mPerTextureStatsRef[256];
    uint16_t mPerTextureStatsCount[256];
    uint16_t TrackedTextureFeedback[32];
    unsigned int TrackedTextureFeedbackMask;
    bool mbIsMultiThreaded;
    std::string msDebugId;
    cTkGnmxContext mGfxContext;
    cTkGnmxContext **mppGfxContextMegaHack;
    std::atomic<int> miTaskBegunCount;
    std::atomic<int> miTaskCompleteCount;
    std::atomic<int> mOwnerThread;
};

SKYSCRAPER_END