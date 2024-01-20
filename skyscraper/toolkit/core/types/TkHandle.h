/**
 * @file TkHandle.h
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

#include <toolkit/core/types/TkTypes.h>

SKYSCRAPER_BEGIN

class cEgSceneNodeTemplate;
class cTkAttachment;

/**
 * @class TkHandle
 * @brief Base node handle type
 */
class TkHandle
{
  public:
    enum
    {
        NumLookupBits      = 0x12,
        NumIncrementorBits = 0xE,
        InvalidLookup      = 0x3FFFF,
    };

    union {
        struct
        {
            uint32_t miLookup : NumLookupBits;
            uint32_t miIncrementor : NumIncrementorBits;
        };
        uint32_t miLookupInt;
    };

    uint64_t GetLookup() { return this->miLookupInt & InvalidLookup; }

    TkHandle *Root(TkHandle *result)
    {
        // Used to be 0x40000, but that overflowed to zero. May need to be 0x3FFFF, but I'm not sure.
        result->miLookup = 0;
        return result;
    }

    bool operator==(TkHandle lHandle)
    {
        return ((lHandle.miLookupInt ^ this->miLookupInt) & InvalidLookup) == 0 &&
               ((lHandle.miLookupInt ^ this->miLookupInt) & 0xFFFC0000) == 0;
    }

    bool operator!=(TkHandle lHandle)
    {
        return ((lHandle.miLookupInt ^ this->miLookupInt) & InvalidLookup) != 0 &&
               ((lHandle.miLookupInt ^ this->miLookupInt) & 0xFFFC0000) != 0;
    }
};

class TkAddNodesHandle
{
  public:
    enum eAddNodesState
    {
        EAddNodesState_None,
        EAddNodesState_Searching,
        EAddNodesState_Adding
    };

    enum eState
    {
        EState_Adding,
        EState_Preparing,
        EState_Complete,
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