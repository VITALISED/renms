/**
 * @file TkSimpleMemoryPool.h
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

SKYSCRAPER_BEGIN

class cTkSimpleMemoryPool
{
  public:
    class cTkBlock
    {
      public:
        uint64_t miSize;
        cTkSimpleMemoryPool::cTkBlock *mpNextContiguousBlock;
        cTkSimpleMemoryPool::cTkBlock *mpPreviousContiguousBlock;
        cTkSimpleMemoryPool::cTkBlock *mpNextBlock;
        cTkSimpleMemoryPool::cTkBlock *mpPreviousBlock;
        bool mbAllocated;
    };

    void *mpMem;
    uint64_t miPoolSizeBytes;
    uint64_t miAllocated;
    uint64_t miAllocatedIncludingHeaders;
    int miBlockPool;
    int miAllocatedBlocks;
    cTkSimpleMemoryPool::cTkBlock *mpFirstFreeBlock;
    cTkSimpleMemoryPool::cTkBlock *mpFirstAllocatedBlock;
};

template <typename T>
class cTkSimpleMemoryPoolWithUserData
{
  public:
    cTkSimpleMemoryPool mPool;
};

SKYSCRAPER_END