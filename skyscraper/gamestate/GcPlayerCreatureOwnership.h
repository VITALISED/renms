/**
 * @file GcPlayerCreatureOwnership.h
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

#include <resources/GcResourceManager.h>
#include <simulation/player/GcPersonalTeleporter.h>
#include <simulation/player/GcPlayerExperienceDirector.h>

#include <simulation/ecosystem/creatures/data/gccreaturepetrewardactions.meta.h>
#include <simulation/ecosystem/gcpeteggspeciesoverridetable.meta.h>
#include <simulation/player/gcscaneffectdata.meta.h>

SKYSCRAPER_BEGIN

class cGcPlayerCreatureOwnership
{
  public:
    sOwnedCreatureInfo maCreatures[18];
    sOwnedCreatureInfo maEggs[18];
    cGcResourceCustomisation maAccessoryCustomisation[18][3];
    bool mabUnlockedSlots[18];
    TkHandle mThumbnailsGroup;
    int miSummonedIndex;
    TkHandle mGroupRootNode;
    cTkMatrix34 mPlacementMatrix;
    cGcPlacementArc mPlacementArc;
    int miPreviewCreature;
    cGcScanEffectData mPreviewScanData;
    cTkColour mPreviewColour;
    float mfPreviewFirstActiveTime;
    float mfPreviewLastActiveTime;
    TkHandle mPreviewNode;
    bool mbClearPreview;
    bool mbShowEmoteArc;
    TkID<128> mEmoteArcID;
    float mfLastRewardActionTime;
    ePetAction meLastRewardActionType;
    cTkSmartResHandle mPetEggResource;
    cTkSmartResHandle mPetHatchEggResource;
    cTkSmartResHandle mLightMaterial;
    cGcPetEggSpeciesOverrideTable *mpPetEggSpeciesOverrideTable;
};

SKYSCRAPER_END