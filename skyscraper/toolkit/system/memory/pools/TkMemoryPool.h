/**
 * @file TkMemoryPool.h
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

#include <toolkit/system/memory/TkMemoryManager.h>
#include <toolkit/utilities/containers/TkBitArray.h>

SKYSCRAPER_BEGIN

enum eMemoryError
{
    EMemoryError_FailedAllocFromFullPool = 0x0,
};

// presumably overrides operator new/delete
template <int>
class AutoPooled
{};

class cTkMemoryPool
{
  public:
    int miType;
    int miAlignment;
    uint64_t muTotalSize;
    cTkBitArray<unsigned int, true, 32> mxErrors;

    virtual ~cTkMemoryPool();
    virtual void Create(void *, int64_t, int);
    virtual void *Malloc(int, int, int *);
    virtual void *Malloc(int, int *);
    virtual void Free(void *);
    virtual void *Realloc(void *, int, int);
    virtual bool ContainsAddress(void *);
    virtual int GetAllocationSize(void *);
    virtual void SetAlignment(int);
    virtual int GetAlignment();
    virtual int64_t GetUsage();
    virtual int64_t GetHighWaterUsage();
    virtual int64_t GetSize();
    virtual void Cleanup();
    virtual void GetAllocInfo(void *, int *, int *);
    virtual bool SetAllocInfo(void *, int, int);
    virtual void ClearStats();
    virtual void OutputStats();
    virtual void FrameSyncEnd(bool);
    virtual bool NeedsFrameSyncEnd();
    virtual void Reset();
    virtual void FlagError(eMemoryError);
    virtual bool HasError(eMemoryError);
    virtual bool NeedsMutex();
    virtual void SetMutex(cTkCSMutex *);
    cTkMemoryPool *GetOverflowPool();
    void *GetBaseAddress();
};

SKYSCRAPER_END