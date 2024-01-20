/**
 * @file GcAtlasCommunityData.h
 * @author VITALISED & Contributors
 * @since 2024-01-15
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

#include <toolkit/utilities/containers/TkVector.h>

SKYSCRAPER_BEGIN

class AtlasCommunalMissionTier
{
  public:
    uint32_t luMissionIndex;
    uint32_t luTierReached;
};

class cGcAtlasCommunityData
{
  public:
    uint64_t muCurrentCMIndex;
    uint64_t muCurrentCMStartEpoch;
    uint64_t muCurrentCMEndEpoch;
    uint64_t muNextCMStartEpoch;
    uint64_t muNextCMEndEpoch;
    uint64_t muMyCMContribution;
    uint64_t muMaxIndividualContribution;
    cTkVector<uint64_t> maContributionLevels;
    uint64_t muCurrentTotalContribution;
    cTkVector<AtlasCommunalMissionTier> mPreviousTiersReached;
    unsigned int muSecondsBetweenCmRefreshes;
    bool mbUpdatePending;
    bool mbRequestUpdate;
    uint64_t muTimeOfLastRefresh;
    uint64_t mRequestHandle;
};

SKYSCRAPER_END