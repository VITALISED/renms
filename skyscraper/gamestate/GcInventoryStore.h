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
#include <toolkit/data/TkMetaData.h>
#include <toolkit/utilities/TkArray.h>
#include <toolkit/utilities/containers/TkUnorderedMap.h>
#include <metadata/gamestate/gcinventoryelement.meta.h>
#include <metadata/gamestate/gcinventoryspecialslot.meta.h>
#include <metadata/reality/gcinventorybasestatentry.meta.h>
#include <metadata/gamestate/gcinventorylayout.meta.h>
#include <metadata/reality/gcinventorystacksizegroup.meta.h>
#include <metadata/reality/gcinventoryclass.meta.h>

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