/**
 * @file TkMemoryManager.cpp
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
