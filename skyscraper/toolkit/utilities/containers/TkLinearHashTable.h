#pragma once

#include <skyscraper.h>

SKYSCRAPER_BEGIN

template <typename T>
class cTkLinearHashTableHash
{ };

template<typename K, typename V, typename H>
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