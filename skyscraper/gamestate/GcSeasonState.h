/**
 * @file GcSeasonState.h
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

#include <toolkit/utilities/containers/TkVector.h>

#include <gamestate/gcseasonsavestateondeath.meta.h>
#include <reality/gcproductdata.meta.h>
#include <reality/gcrealitysubstancedata.meta.h>
#include <reality/gctechnology.meta.h>

SKYSCRAPER_BEGIN

class cGcSeasonState
{
  public:
    struct sSeasonalMilestoneProgress
    {
        int miStageIndex;
        int miMilestoneIndex;
        float mfCurrentValue;
        float mfUnitProgress;
        bool mbRewardFitsInInventory;
        bool mbRewardCollected;
        bool mbRevealed;
        bool mbVisible;
    };

    struct sSeasonalStageProgress
    {
        cTkVector<cGcSeasonState::sSeasonalMilestoneProgress> maMilestones;
        float mfProgress;
    };

    struct sPinnedMilestone
    {
        int miStageIndex;
        int miMilestoneIndex;
    };

    struct sPendingMilestoneReward
    {
        int miStageIndex;
        int miMilestoneIndex;
    };

    struct sSeasonInitialBuilding
    {
        cTkVector3 mPosition;
        cTkSeed mSeed;
        float mfRadius;
    };

    struct sBuildingPreventionArea
    {
        cTkVector3 mPosition;
        float mfRadius;
    };

    cTkVector<cGcSeasonState::sSeasonalStageProgress> maStageProgress;
    cGcSeasonState::sPinnedMilestone mPinnedMilestone;
    cGcSeasonState::sPendingMilestoneReward mPendingMilestoneReward;
    cTkVector<uint64_t> maRendezvousUAs;
    cTkVector<cGcSeasonState::sSeasonInitialBuilding> maInitialBuildings;
    robin_hood::detail::Table<
        true, 80, uint64_t, cTkVector<cGcSeasonState::sBuildingPreventionArea>, robin_hood::hash<uint64_t, void>,
        std::equal_to<uint64_t>>
        mBuildingPreventionAreas;
    cGcSeasonSaveStateOnDeath mStateOnDeath;
    cTkVector<cGcTechnology> maReplacedTechnologies;
    cTkVector<cGcProductData> maReplacedProducts;
    cTkVector<cGcRealitySubstanceData> maReplacedSubstances;
    bool mbWantToUpdateRewardAvailability;
    bool mbHasCollectedFinalReward;
    bool mbFinalRewardFitsInInventory;
};

SKYSCRAPER_END