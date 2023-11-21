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

#include <vulkan/vulkan.h>

SKYSCRAPER_BEGIN

struct TkRenderPassDesc
{
    VkAttachmentDescription lAttachments[16];
    VkAttachmentReference lAttachRefs[16];
    VkAttachmentReference lDepthRef;
    VkSubpassDescription lSubpass;
    VkSubpassDependency lDepthBarrier;
    VkImageView_T *lFbAttachments[16];
    VkRenderPassCreateInfo lRenderPassInfo;
    VkFramebufferCreateInfo lFramebufInfo;
};

SKYSCRAPER_END