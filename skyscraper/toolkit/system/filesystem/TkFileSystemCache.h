/**
 * @file TkFileSystemCache.h
 * @author VITALISED & Contributors
 * @since 2024-01-03
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

#include <toolkit/system/memory/pools/TkSimpleMemoryPool.h>
#include <toolkit/utilities/containers/TkVector.h>
#include <toolkit/utilities/string/TkString.h>

SKYSCRAPER_BEGIN

class cTkFileSystemCache
{
  public:
    struct sFileSystemCacheData
    {
        uint64_t muLastUsed;
        uint64_t muBuffSize;
    };

    struct sCachedFileSection
    {
        int64_t miFileOffset;
        int64_t miCachedSize;
        cTkFileSystemCache::sFileSystemCacheData *mpPoolBlock;
        bool mbInFlight;
    };

    struct sAsyncPrecacheOp
    {
        int mOp;
        cTkFileSystemCache::sCachedFileSection *mpCachedFile;
    };

    struct sCompressionData
    {
        void *mpWorkBuff;
        int miWorkBuffSize;
        bool mbCompressed;
    };

    void *mpPoolMem;
    cTkSimpleMemoryPoolWithUserData<cTkFileSystemCache::sFileSystemCacheData> mPool;
    std::multimap<cTkFixedString<260, char>, cTkFileSystemCache::sCachedFileSection> mLookup;
    std::recursive_mutex mMutex;
    cTkVector<cTkFixedString<256, char>> mPathEndMatches;
    std::list<cTkFileSystemCache::sAsyncPrecacheOp> mAsyncPrecacheOps;
    int64_t miMaxFileSize;
    cTkFileSystemCache::sCompressionData mCompressionData;
};

SKYSCRAPER_END