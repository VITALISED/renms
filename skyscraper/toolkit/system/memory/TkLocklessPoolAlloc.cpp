/**
 * @file TkLocklessPoolAlloc.cpp
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