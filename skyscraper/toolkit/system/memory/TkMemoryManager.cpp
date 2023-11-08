#include <skyscraper.h>
#include <toolkit/system/memory/TkMemoryManager.h>

// SKYSCRAPER_BEGIN

// // nt thread stuff in this func makes it a pain to reverse
// int cTkMemoryManager::GetBackingPoolIndexFromPool(int liMemType)
// {
//     if (liMemType == -3) { return this->mpMemPoolDefinitionList[this->miGlobalPoolInd].meBackingPool; }
//     else if (liMemType == -1) {}
//     else if (liMemType == this->miDblBufPoolInd) {}
// }

// cTkMemoryPool *cTkMemoryManager::GetBackingPool(int liPool)
// {
//     if (liPool < 0) {}

//     if (liPool >= this->miNumBackingPools) {}

//     return this->mpapBackingMemoryPools[liPool];
// }

// void *cTkMemoryManager::Malloc(
//     int liSize, const char *lpacFile, int liLine, const char *lpacFunction, int liAlign, int liPool)
// {
//     if (liAlign && !(liAlign & (liAlign - 1)))
//     {
//         // handle non power of two alignment
//     }

//     if ((liPool == -2) && cTkMemoryManager::mgbConstructed)
//     {
//         // i hate this with a fucking passion
//         return _aligned_malloc(liSize, liAlign);
//     }

//     int                 liBackingPoolIndex = this->GetBackingPoolIndexFromPool(liPool);
//     cTkMemoryPool      *lpBackingPool      = this->GetBackingPool(liBackingPoolIndex);
//     cTkBackingPoolData *lpBackingPoolData  = &this->mpBackingPoolData[liBackingPoolIndex];

//     if (lpBackingPoolData)
//     {
//         int liAllocatedSize;

//         if (lpBackingPoolData->mbUseFixedPools && liAlign > 0)
//         {
//             liAllocatedSize = liSize;
//             this->mFixedPools
//         }
//     }

//     return nullptr; // todo: finish
// }

// SKYSCRAPER_END
