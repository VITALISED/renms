/**
 * @file TkLinearHashTable.h
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

SKYSCRAPER_BEGIN

template <typename T>
class cTkLinearHashTableHash
{};

struct cTkHashTableHashPassthrough
{};

template <typename K, typename V, typename H>
class cTkLinearHashTable
{
    class cTkListNode
    {
        std::pair<K, V> mValue;
        H mHash;
        cTkLinearHashTable<K, V, H>::cTkListNode *mpNext;
        cTkLinearHashTable<K, V, H>::cTkListNode *mpPrev;
        bool mbUsed;
    };

    cTkLinearHashTable<K, V, H>::cTkListNode *mpNodes;
    cTkLinearHashTable<K, V, H>::cTkListNode **mapBucketTable;
    cTkLinearHashTable<K, V, H>::cTkListNode *mpFirstFreeNode;
    int miCapacity;
    int miSize;
    int miTableSize;
};

SKYSCRAPER_END