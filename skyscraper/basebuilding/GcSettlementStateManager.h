/**
 * @file GcSettlementStateManager.h
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

#include <gamestate/gcsettlementstate.meta.h>
#include <simulation/environment/gcbuildingclassification.meta.h>

SKYSCRAPER_BEGIN

class cGcSettlementStateManager
{
  public:
    std::array<eBuildingClass, 48> maeOwnedSettlementBuildingClasses;
    std::array<cTkSeed, 48> maOwnedSettlementBuildingSeeds;
    cGcSettlementState *mpOwnedSettlementState;
    cGcSettlementState *mpSettlementToReport;
    cGcSettlementState mSettlementToAbandon;
    TkID<128> mCachedPendingCustomJudgementID;
    uint64_t mu64NextBuildingUpgradeTimestamp;
    bool mbHasBuildingClassesAndSeeds;
    bool mbOwnedSettlementPendingUpload;
    bool mbOwnedSettlementUploadFailed;
    bool mbAbandonSettlementUploadFailed;
    bool mbReportSettlementFailed;
    bool mbStoreSettlementTeleportEndpointFailed;
    bool mbOnBuildingStateChangedPending;
    bool mbClaimingFirstSettlement;
    bool mbCompletAllClumpsChecked;
};

SKYSCRAPER_END