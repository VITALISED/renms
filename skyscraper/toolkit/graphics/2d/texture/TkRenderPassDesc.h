#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

struct TkRenderPassDesc
{
    VkAttachmentDescription lAttachments[16];
    VkAttachmentReference lAttachRefs[16];
    VkAttachmentReference lDepthRef;
    VkSubpassDescription lSubpass;
    VkSubpassDependency lDepthBarrier;
    struct VkImageView_T *lFbAttachments[16];
    VkRenderPassCreateInfo lRenderPassInfo;
    VkFramebufferCreateInfo lFramebufInfo;
};

SKYSCRAPER_END