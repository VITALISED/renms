/**
 * @file TkResource.h
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
#include <toolkit/resources/TkResourceDescriptor.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/utilities/string/TkString.h>

#include <atomic>
#include <set>

SKYSCRAPER_BEGIN

class cTkSmartResHandle
{
  public:
    TkStrongType<int, TkStrongTypeIDs::TkResHandleID> miInternalHandle;
};

template <typename T>
class cTkTypedSmartResHandle
{
    cTkSmartResHandle mHandle;
    T *mpPointer;
};

class cTkResource
{
  public:
    int32_t miType;
    cTkFixedString<256, char> msName;
    int32_t mxFlags;
    int32_t mAsyncOpHandle;
    TkStrongType<int32_t, TkStrongTypeIDs::TkResHandleID> mHandle;
    std::atomic<uint32_t> muRefCount;
    std::atomic<bool> mbLoaded;
    bool mbNoQuery;
    bool mbError;
    bool mbReplaceWithDefault;
    bool mbLazyDelete;
    bool mbPersistent;
    cTkVector<TkStrongType<int32_t, TkStrongTypeIDs::TkResHandleID>> mSubResources;
    std::set<cTkSmartResHandle> mOwnedResources;
    cTkResourceDescriptor mDescriptor;
    uint16_t muHotRequestNumber;

    virtual ~cTkResource();
    virtual bool IsLoaded();
    virtual void SetDescriptor(const cTkResourceDescriptor *lpDescriptor);
    virtual int32_t GetDataSize()            = 0;
    virtual bool OnResourceLoaded()          = 0;
    virtual uint32_t GetDeletionFrameDelay() = 0;
    virtual cTkResource *Clone()             = 0;
    virtual void CloneInternal(const cTkResource *lpResource);
    virtual void Release() = 0;
    virtual bool Equals(const char *lpacName, const cTkResourceDescriptor *lpDescriptor, int32_t liType);
};

SKYSCRAPER_END