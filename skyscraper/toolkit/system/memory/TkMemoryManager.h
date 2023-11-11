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

#include <toolkit/system/TkCSMutex.h>
#include <toolkit/system/memory/TkLocklessPoolAlloc.h>

SKYSCRAPER_BEGIN

class cTkMemoryPool;

enum eTkMemType
{
    EMemoryPool_Physics,
    EMemoryPool_SingleBuffer,
    EMemoryPool_DoubleBuffer,
    EMemoryPool_DoubleBufferPausable,
    EMemoryPool_IO,
    EMemoryPool_Network,
    EMemoryPool_Resources,
    EMemoryPool_Audio,
    EMemoryPool_Graphics,
    EMemoryPool_Compute,
    EMemoryPool_Nodes,
    EMemoryPool_AnimStages,
    EMemoryPool_BlockAllocator,
    EMemoryPool_GraphicsContext,
    EMemoryPool_CommandBuffers,
    EMemoryPool_Debug,
    EMemoryPool_Metadata,
    EMemoryPool_NodeAllocator,
    ENumTkMemoryPools,
};

enum eMemoryHeapType
{
    ELinearHeap,
    EDynamicHeap,
    ESmallBlockHeap,
    ESingleBufferHeap,
    EDoubleBufferHeap,
    EDoubleBufferHeapPausable,
    EAtomicLinearHeap,
    EHeapType_Num,
};

template <unsigned int liSize, unsigned int liAlignment>
class cTkAlignedBlock
{
    unsigned __int8 data_[(liAlignment == 1) ? liSize * (liAlignment + 3) : liSize * liAlignment];
};

template <typename T>
struct StackAllocator : std::allocator<T>
{
    using value_type = T;

    template <typename U>
    struct rebind
    {
        using other = StackAllocator<U>;
    };

    struct Source
    {
        cTkAlignedBlock<sizeof(T), alignof(T)> stack_buffer_;
        bool used_stack_buffer_;
    };
};

template <typename T>
class TkSTLAllocatorShim : public std::allocator<T>
{
    template <typename U>
    struct rebind
    {
        using other = TkSTLAllocatorShim<U>;
    };
};

class cTkMemoryPoolDefinition
{
  public:
    const char *macName;
    int mePool;
    int meBackingPool;
};

class cTkMemoryBackingPoolDefinition
{
  public:
    int meBackingPool;
    eMemoryHeapType meHeapType;
    const char *macName;
    __int64 miSize;
    unsigned int miThreadID;
    int mxFlags;
};

class cTkBitAlloc
{
    unsigned __int64 *mpBlocks;
    unsigned int muNextBlock;
    unsigned int muNumBlocks;
    unsigned int muNumSlots;
    unsigned int muNumUsedSlots;
    int miPoolId;
};

class cTkSlotAlloc
{
    cTkFixedString<64, char> mName;
    cTkBitAlloc mAllocator;
    unsigned __int64 muStart;
    unsigned __int64 muEnd;
    unsigned int muSlotSize;
    unsigned int muAlignment;
    unsigned int muTotalAllocs;
    unsigned int muHighWaterMark;
    int miPoolId;
};

class cTkAllocInfo
{
    std::atomic<int> mHashKey;
    int miLine;
    const char *mpacFile;
    const char *mpacFunction;
    std::atomic<__int64> miUsage;
    std::atomic<__int64> miMaxUsage;
    std::atomic<int> miNumAllocsLive;
    std::atomic<int> miNumAllocsTotal;
};

class cTkMemoryManager
{
  public:
    class cTkPoolData
    {
      public:
        std::atomic<__int64> miUsage;
        std::atomic<__int64> miMaxUsage;
        cTkAllocInfo *mpAllocInfo;
    };

    class cTkBackingPoolData
    {
      public:
        cTkCSMutex mMutex;
        bool mbNeedsMutex;
        bool mbUseFixedPools;
    };

    static const bool mgbConstructed = true; // cba to fetch this, besides we're gonna inject after this no matter what

    cTkMemoryBackingPoolDefinition *mpMemBackingPoolDefinitionList;
    cTkMemoryPoolDefinition *mpMemPoolDefinitionList;
    cTkMemoryPool **mpapBackingMemoryPools;
    cTkMemoryPool *mpCurrentBackingPool;
    cTkMemoryManager::cTkPoolData *mpPoolData;
    cTkMemoryManager::cTkBackingPoolData *mpBackingPoolData;
    unsigned __int64 mu64TotalSize;
    int miNumBackingPools;
    int miNumPools;
    int miPoolsPerThread;
    int miThreads;
    int miDblBufPoolInd;
    int miDblBufPausablePoolInd;
    int miGlobalPoolInd;
    bool mbWasPausableThisFrame;
    bool mbDebugMemoryAvailable;
    unsigned __int64 mu64ExternalMemSize;
    unsigned __int64 miFrameNum;
    unsigned __int64 miPausableFrameNum;
    cTkLocklessMultiPoolAllocator mFixedPools;
    int miFirstPerThreadPool[64];
    void (*mOutOfMemoryMessageCallback)();

    void *Malloc(int liSize, const char *lpacFile, int liLine, const char *lpacFunction, int liAlign, int liPool);
    void *Realloc(
        void *lpPointer, int liSize, char *lpacFile, int liLine, const char *lpacFunction, unsigned int liAlignment);
    void *Free();
    cTkMemoryPool *GetBackingPool(int liPool);
    int GetBackingPoolIndexFromPool(int liMemType);
};

SKYSCRAPER_END