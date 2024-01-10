/**
 * @file TkFileSystem.h
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

#include <sceFios2.h>
#include <toolkit/system/filesystem/TkFileSystemCache.h>
#include <toolkit/system/filesystem/fios2/TkFileSystemFios2.h>
#include <toolkit/system/memory/pools/TkMemoryPool.h>
#include <toolkit/utilities/containers/TkStackContainer.h>
#include <toolkit/utilities/containers/TkTFixedFreeList.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/utilities/string/TkString.h>

SKYSCRAPER_BEGIN

enum eFileOpenMode
{
    EFOM_Read,
    EFOM_Write,
    EFOM_Append,
};

class cTkFilename : public cTkFixedString<128, char>
{};

class cTkFileSystem
{
  public:
    /**
     * Methods
     */

    inline bool IsModded()
    {
        if (this->mpData) return this->mpData->mbIsModded;
        return false;
    };

    /**
     * Custom implementations
     */

    static cTkFileSystem *GetInstance();

    /**
     * Detail declarations
     */

    DECLARE_METHOD_DETAIL(IsModded, bool(cTkFileSystem *), "48 8B 01 48 85 C0 74 ? 0F B6 80 92 26 00 00");

    /**
     * Members
     */

    struct Data : public AutoPooled<4>
    {
        cTkTFixedFreeList<FIOS2HANDLE, 4> mFileHandleFreeList;
        SceFiosPsarcDearchiverContext mDearchiverContext;
        void *mDearchiverWorkBuffer;
        cTkStackVector<cTkMountedFIOSArchive, 64> mMountedFIOSArchives;
        bool mbMountBanks;
        bool mbTransparentMounting;
        bool mbIsModded;
        bool mbIsTampered;
        cTkFixedString<256, char> mArchiveRoot;
        cTkFixedString<256, char> mModArchiveRoot;
        cTkFixedString<256, char> mWorkingRoot;
        cTkFixedString<256, char> mArchiveMountPoint;
        std::shared_ptr<cTkFileSystemCache> mpFileSystemCache;
        cTkVector<cTkFiosCacheDesc> mFiosBankCaches;
        cTkVector<cTkFiosCacheDesc> mFiosSystemCaches;
        std::vector<void(__cdecl *)(int *)> mAsyncCompletionCallbacks;
    };

    cTkFileSystem::Data *mpData;
};

SKYSCRAPER_END
