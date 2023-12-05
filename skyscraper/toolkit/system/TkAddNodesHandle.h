/**
 * @file TkAddNodesHandle.h
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

#include <toolkit/attachments/TkAttachment.h>

SKYSCRAPER_BEGIN

class TkAddNodesHandle
{
    enum eAddNodesState
    {
        EAddNodesState_None,
        EAddNodesState_Searching,
        EAddNodesState_Adding
    };

    enum eState
    {
        // Empty?
    };

    TkStrongType<int, TkStrongTypeIDs::TkResHandleID> mSceneGraphResource;
    TkHandle mParentNode;
    TkHandle mNode;
    TkHandle mLastAddedNode;
    std::shared_ptr<TkAddNodesHandle> mpAddReferencedResourceHandle;
    uint64_t mu64Timeout;
    cEgSceneNodeTemplate *mpLastAddedTemplate;
    cTkAttachment *mpCurrentAttachment;
    int miCount;
    eAddNodesState meAddNodesState;
    eState meState;
};

SKYSCRAPER_END