#pragma once

#include <skyscraper.h>
#include <toolkit/graphics/2d/texture/TkRenderPassDesc.h>

SKYSCRAPER_BEGIN

class cTkGnmxContext
{
    TkRenderPassDesc mRenderPassDesc;
    VkRenderPassBeginInfo mBeginPassInfo;
    struct VkRenderPass_T *mCurrentRenderPass;
    struct VkFramebuffer_T *mCurrentFramebuffer;
    cTkGnmxContext *mpParentContext;
    VkClearValue mClears[16];
    bool mbClearQueued;
    struct VkCommandBuffer_T *mCommandList;
    struct VkCommandPool_T *mCommandAllocator;
    unsigned int mCommandListType;
    bool mbRootSigSet;
    bool mbInitialStateSet;
    bool mbCommandListOpen;
    bool mbOnlyVSPS;
    bool mbIsMultiThreaded;
    bool mbSubmitted;
};

SKYSCRAPER_END