#pragma once

#include <skyscraper.h>
#include <toolkit/data/TkMetaData.h>
#include <toolkit/utilities/TkArray.h>
#include <toolkit/utilities/containers/TkUnorderedMap.h>
#include <metadata/source/gamestate/gcinventoryelement.meta.h>
#include <metadata/source/gamestate/gcinventoryspecialslot.meta.h>
#include <metadata/source/reality/gcinventorybasestatentry.meta.h>
#include <metadata/source/gamestate/gcinventorylayout.meta.h>
#include <metadata/source/reality/gcinventorystacksizegroup.meta.h>
#include <metadata/source/reality/gcinventoryclass.meta.h>

SKYSCRAPER_BEGIN

class cGcInventoryStore
{
    cTkBitArray<unsigned __int64, 16> mxValidSlots[16];
    __int16 miWidth;
    __int16 miHeight;
    __int16 miCapacity;
    std::vector<cGcInventoryElement> mStore;
    std::vector<cGcInventoryElement> mStoreHistory;
    std::vector<cGcInventorySpecialSlot> maSpecialSlots;
    std::vector<cGcInventoryBaseStatEntry> maBaseStats;
    cGcInventoryLayout mLayoutDescriptor;
    bool mbAutoMaxEnabled;
    bool mbIsCool;
    eInventoryStackSizeGroup meStackSizeGroup;
    cGcInventoryClass mClass;
    cTkFixedString<256,char> mInventoryName;
    cTkUnorderedMap<TkID<256>, int, TkIDUnorderedMap::Hash256> mTechGroupCounts;
};


SKYSCRAPER_END