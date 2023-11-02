#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

class cTkLocklessPoolAllocator
{
    unsigned int muNumSlots;
    unsigned int muSlotSize;
    std::atomic<__int64> mFreeListHead;
    unsigned __int64 miBaseAddress;
    bool mbOwnsMemory;
    std::atomic<int> miHighWatermark;
    std::atomic<int> miOpCount;
    std::atomic<int> miUsage;
};

class cTkLocklessMultiPoolAllocator
{
    struct sPoolConfig
    {
        int miMinAlloc;
        int miSlotSize;
        int miNumSlots;
    };

    int miNumPools;
    cTkLocklessPoolAllocator *mpPools;
    cTkLocklessMultiPoolAllocator::sPoolConfig *mpPoolConfigs;
    unsigned __int64 miStart;
    unsigned __int64 miEnd;
};

SKYSCRAPER_END