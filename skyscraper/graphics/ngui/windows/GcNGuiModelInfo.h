/**
 * @file GcNGuiModelInfo.h
 * @author VITALISED & Contributors
 * @since 2023-12-11
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

#include <graphics/ngui/GcNGuiNodeInfo.h>
#include <graphics/ngui/windows/GcNGuiWindow.h>
#include <toolkit/attachments/TkAttachment.h>
#include <toolkit/simulation/TkSeed.h>

#include <toolkit/scene/materials/tkmaterialdata.meta.h>

SKYSCRAPER_BEGIN

class cGcDebugMaterialCacheEntry
{
  public:
    TkStrongType<int, TkStrongTypeIDs::TkResHandleID> mMaterial;
    std::string mMaterialName;
    cTkMaterialData *mpMaterialData;
    cTkVector<cTkSmartResHandle> maTexures;
};

class cGcNGuiModelInfo : public cGcNGuiWindow
{
  public:
    class cGcAttachmentPair
    {
      public:
        cTkAttachment *mpAttachment;
        cTkFixedString<256, char> mName;
    };

    cTkFixedString<512, char> mNewAltId;
    cTkSeed mSelectedResSeed;
    cGcNGuiNodeInfo *mpSelectedNode;
    TkHandle mSelectedSceneNode;
    int miSelectedNodeCount;
    cTkVector<cGcNGuiModelInfo::cGcAttachmentPair> mAttachmentCache;
    cTkVector<cTkAttachmentData *> mAttachmentDataCache;
    cTkVector<cGcDebugMaterialCacheEntry> mMaterialCache;
};

SKYSCRAPER_END