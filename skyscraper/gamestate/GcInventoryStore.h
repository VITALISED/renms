/**
 * @file GcInventoryStore.h
 * @author VITALISED & Contributors
 * @since 2023-12-09
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

#include <toolkit/core/types/TkID.h>
#include <toolkit/utilities/containers/TkBitArray.h>
#include <toolkit/utilities/containers/TkUnorderedMap.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <gamestate/gcinventoryelement.meta.h>
#include <gamestate/gcinventorylayout.meta.h>
#include <gamestate/gcinventoryspecialslot.meta.h>
#include <reality/gcinventorybasestatentry.meta.h>
#include <reality/gcinventoryclass.meta.h>
#include <reality/gcinventorystacksizegroup.meta.h>

SKYSCRAPER_BEGIN

class cGcInventoryStore
{
  public:
    cTkBitArray<uint64_t, true, 16> mxValidSlots[16];
    int16_t miWidth;
    int16_t miHeight;
    int16_t miCapacity;
    cTkVector<cGcInventoryElement> mStore;
    cTkVector<cGcInventoryElement> mStoreHistory;
    cTkVector<cGcInventorySpecialSlot> maSpecialSlots;
    cTkVector<cGcInventoryBaseStatEntry> maBaseStats;
    cGcInventoryLayout mLayoutDescriptor;
    bool mbAutoMaxEnabled;
    bool mbIsCool;
    eInventoryStackSizeGroup meStackSizeGroup;
    cGcInventoryClass mClass;
    cTkFixedString<256, char> mInventoryName;
    cTkUnorderedMap<TkID<256>, int, TkIDUnorderedMap::Hash256> mTechGroupCounts;
};

SKYSCRAPER_END