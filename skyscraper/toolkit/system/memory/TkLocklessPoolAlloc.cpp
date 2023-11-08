#include <toolkit/system/memory/TkLocklessPoolAlloc.h>

// SKYSCRAPER_BEGIN

// void *cTkLocklessPoolAllocator::Alloc()
// {
//     // for(this->mFreeListHead.compare_exchange_strong())
// }

// void *cTkLocklessMultiPoolAllocator::Alloc(unsigned int luSize)
// {
//     if (luSize < this->mpPoolConfigs->miMinAlloc) { return NULL; }

//     if (luSize > this->mpPoolConfigs[this->miNumPools - 1].miSlotSize) { return NULL; }

//     int unk1 = this->miNumPools >> 1;
//     int unk2 = NULL;

//     if (luSize > this->mpPoolConfigs[unk1 - 1].miSlotSize) { unk2 = unk1; }

//     if (unk2 >= this->miNumPools) { return NULL; }
// }

// SKYSCRAPER_END