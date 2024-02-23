/**
 * @file GcMaintenanceComponent.h
 * @author VITALISED & Contributors
 * @since 2024-01-22
 *
 * Copyright (C) 2024  VITALISED & Contributors
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

#include <gamestate/sBasePersistentData.h>
#include <graphics/frontend/popups/GcFrontendPopup.h>
#include <simulation/components/gameplay/GcObjectPlacementComponent.h>
#include <simulation/solarsystem/buildings/GcBuilding.h>
#include <toolkit/simulation/components/TkComponent.h>

#include <simulation/components/gameplay/gcmaintenancecomponentdata.meta.h>

SKYSCRAPER_BEGIN

union MaintenanceFlags {
    struct InternalData
    {
        uint16_t mbForcedBroken : 1;
        uint16_t mbForcedFixed : 1;
        uint16_t mbManualOn : 1;
        uint16_t muCounter : 12;
        uint16_t mbDisableSynchronise : 1;
    };

    MaintenanceFlags::InternalData mData;
    uint16_t mBlob;
};

class cGcMaintenanceComponent : public cTkComponent
{
  public:
    cGcMaintenanceComponentData *mpData;
    cTkVector<ePopupAction> maMaintenanceEmptySlotActions;
    int mPopupActions;
    cGcInventoryStore mInventoryStore;
    int miMaintenanceSlotsCount;
    uint64_t muiSlotStates;
    MaintenanceFlags mFlags;
    TkHandle mInteractLocator;
    TkHandle mInteractInWorld;
    float mafPreInstalledTechPeriodMultipliers[16];
    float mafItemAmountAccumulators[16];
    float mafItemDamageTimers[16];
    int64_t miLastUpdatedTime;
    bool mbHasBeenInteractedWith;
    cGcBuilding *mpBuilding;
    cGcObjectPlacementComponent *mpObjectPlacement;
    cTkVector3 mCentreOffset;
    TkHandle mModelNode;
    bool mbIsSetup;
    cTkVector3 mLastPosition;
    float mfCheckSetupTimer;
    uint16_t mLastChangeHash;
    sComponentBaseObjectHandle mBaseObjectHandle;
    cTkFixedString<256, char> mTitle;
    uint64_t mCompletedTimestamp;
    uint64_t mBrokenTimestamp;
    bool mbShouldSave;
};

SKYSCRAPER_END