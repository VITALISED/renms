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
    void Update();
    void UpdateOwnedSettlementBuildingsClasses();
    void UpdateOwnedSettlementBuildingsConstruction();
    void SetOwnedSettlementState(cGcSettlementState *lpSettlementState, const bool lbIsNewSettlement);
    void TryStoreOwnedSettlementTeleportEndpoint();
    void RefreshOwnedSettlementNextBuildingUpgrade();
    void ClearOwnedSettlement();
    bool OwnsSettlement();
    const cGcSettlementState &GetOwnedSettlementState();
    bool HasOwner(cGcSettlementState &lSettlementState);
    bool IsOwnedByLocalUser(const cGcSettlementState &lSettlementState);
    bool ClaimSettlement(
        cGcSettlementState &lSettlementState, const cGcSolarSystemData &lSolarSystemData, bool lbIsFirstSettlement);
    void ClearSettlementState(cGcSettlementState &lSettlementState);
    void ResetOwnedSettlementProduction(const eAlienRace leAlienRace);
    void UpdateOwnedSettlementSlotProduct(const uint64_t lu64TimerOffset);
    cTkFixedString<64, char> &GetSettlementName(const cGcSettlementState &lSettlementState);
    cGcBuilding *GetOwnedSettlementHubBuilding();
    cGcBuilding *GetHubBuilding(const cGcSettlementState &lSettlementState);
    bool OwnedSettlementHasAnyBuildingsInProgress(bool lbIgnoreIfTimerActive, uint64_t &luOutTimeRemaining);
    // FIXME: wrong ret, but probably still an integer of some sort
    int64_t GetOwnedSettlementNumUnstartedBuildings();
    bool AddPerkToOwnedSettlement(const TkID<128> &lBasePerkId, uint64_t lSeedValue);
    bool AddPerk(cGcSettlementState &lSettlementState, const TkID<128> &lBasePerkId, uint64_t lSeedValue);
    TkID<128> &GenerateProcPerkId(const TkID<128> &lBasePerkId, uint64_t lBaseSeedValue);
    bool RemovePerkFromOwnedSettlement(const TkID<128> &lPerkId);
    bool ApplyStatChangeToOwnedSettlement(
        const cGcSettlementStatChange &lStatChange, const cTkSeed &lSeed, int liAmountChanged);
    int GetTotalStatValue(cGcSettlementState &lSettlementState, const eSettlementStatType leStatType);
    float GetNormalisedStatValues(cGcSettlementState &lSettlementState, eSettlementStatType leStatType);
    // FIXME: yet another unknown enum
    int GetStatLevel(cGcSettlementState &lSettlementState, const eSettlementStatType leStatType);
    void GetOwnedSettlementJudgementTypeAndTime(
        eSettlementJudgementType &leSettlementJudgementType, uint64_t &lu64Time);
    void UpdateOwnedSettlementJudgementTrigger();
    float GetOwnedSettlementCycleProductivityFactor();
    float GetOwnedSettlementCycleItemProductionRate(const TkID<128> &lElementId);
    float GetOwnedSettlementDebtPaymentRatePerSecond();
    bool IsOwnedSettlementOfficeComplete();
    void ReportSettlement(cGcSettlementState &lSettlementState);
    bool UploadSettlement(const cGcSettlementState &lSettlementState);
    bool SendReportSettlement(const cGcSettlementState &lSettlementState);
    uint64_t GetProcPerkSeed(const TkID<128> &lBasePerkId, uint64_t lBaseSeedValue);
    void AddNewStatsMessage(eSettlementStatType leStat, int liAmount);
    float GetSettlementBuiltPercentage(const cGcSettlementState &lSettlementState);
    void UpdateMpSettlementState();

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