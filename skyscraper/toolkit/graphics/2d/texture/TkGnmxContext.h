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

#include <toolkit/graphics/2d/texture/TkRenderPassDesc.h>
#include <vulkan/vulkan.h>

SKYSCRAPER_BEGIN

class cTkGnmxContext
{
    TkRenderPassDesc mRenderPassDesc;
    VkRenderPassBeginInfo mBeginPassInfo;
    VkRenderPass_T *mCurrentRenderPass;
    VkFramebuffer_T *mCurrentFramebuffer;
    cTkGnmxContext *mpParentContext;
    VkClearValue mClears[16];
    bool mbClearQueued;
    VkCommandBuffer_T *mCommandList;
    VkCommandPool_T *mCommandAllocator;
    uint32_t mCommandListType;
    bool mbRootSigSet;
    bool mbInitialStateSet;
    bool mbCommandListOpen;
    bool mbOnlyVSPS;
    bool mbIsMultiThreaded;
    bool mbSubmitted;
};

SKYSCRAPER_END