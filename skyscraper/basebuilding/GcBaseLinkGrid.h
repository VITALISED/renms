/**
 * @file GcBaseLinkGrid.h
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

#include <basebuilding/GcBaseLinkGroups.h>
#include <simulation/environment/scanning/GcRegionHotspots.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <gamestate/basebuilding/gcbasebuildingentry.meta.h>
#include <simulation/gcregionhotspottypes.meta.h>

SKYSCRAPER_BEGIN

class cGcLinkGrid
{
  public:
    struct sLinkGroup
    {
        int miPositiveRate;
        int miNegativeRate;
        int miPositiveDecayingRate;
        float mfTotalAmount;
        int miTotalStorage;
        int miNumSpareCapacityObjects;
        int miNumNonEmptyObjects;
        int miTotalObjects;
        int miTotalPassiveObjects;
        int miTotalStorageOnlyObjects;
        int miPotentialPositiveRate;
        int miHotspotTypes;
    };

    struct sLinkObjectInstance
    {
        uint16_t muiBufferIndex;
        uint16_t muiLinkIndex;
        const cGcBaseBuildingEntry *mpEntry;
        uint64_t mu64SavedTimestamp;
        float mfAmountEstimate;
        bool mbConnectionEnabled;
        bool mbRateEnabled;
        uint8_t muiRateLevel;
        uint8_t muiDependentsDisabled;
        float mfHotspotStrength;
        eHotspotType meHotspotType;
        cGcRegionHotspots::sHotspotHandle mHotspotHandle;
        uint16_t muiGroupIndex;
    };
    cTkVector<cGcLinkGrid::sLinkObjectInstance> mObjects;
    cTkVector<cGcLinkGrid::sLinkGroup> mGroups;
    uint16_t muiGroupsCount;
    bool mbHasDayNightDependents;
    bool mbHasStormDependents;
    uint64_t mu64NextDueChangeTimestamp;
    uint64_t mu64LastSavedTimestamp;
    cGcBaseLinkMap *mpLinkMap;
};

SKYSCRAPER_END