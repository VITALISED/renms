/**
 * @file GcFleetFrigate.h
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

#include <simulation/components/gameplay/GcMaintenanceComponent.h>
#include <simulation/player/GcPlayerCommon.h>
#include <simulation/player/GcPlayerExperienceDirector.h>
#include <toolkit/maths/geometry/TkAABB.h>
#include <toolkit/utilities/containers/TkBitArray.h>
#include <toolkit/utilities/containers/TkVector.h>

#include <gamestate/gcfleetfrigatesavedata.meta.h>
#include <reality/gcalienrace.meta.h>
#include <reality/gcfrigateclass.meta.h>
#include <reality/gcinventoryclass.meta.h>
#include <simulation/gcfrigatetraitdata.meta.h>

SKYSCRAPER_BEGIN

class cGcFleetFrigate
{
  public:
    void AddTrait(const cGcFrigateTraitData *lpTrait, bool lbUpdateInventoryClass);
    void AwardLevelUpStats();
    cGcAIShipSpawn *GetAIShipSpawn();
    bool GetCanLevelUp(float &lfOutUnitProgressToNextLevel);
    cTkFixedString<128, char> &GetCaptainName(bool lbUseNormalTitle, bool lbAddPrefix);
    cGcInventoryElement &GetCargo();
    float GetCost();
    cTkFixedString<32, char> &GetCustomName();
    const cTkVector<cGcMaintenanceComponent *> *GetDamagedMaintenanceComponents();
    cGcFleetExpedition *GetExpedition();
    eFrigateClass GetFrigateClass();
    const char *GetFrigateClassIconString();
    cTkFixedString<127, char> &GetName();
    cTkFixedString<127, char> &GetNameFromSeed(const cTkSeed &lSeed, eFrigateClass leClass);
    int GetNumberOfExpeditionsCompleted();
    int GetNumberOfTimesDamaged();
    cTkUserIdBase<cTkFixedString<64, char>> &GetOwnerId();
    const cGcPlayerCommon *GetPirateDefencePlayer();
    cGcPlayerFleetManager *GetPlayerFleetManager();
    cGcFleetFrigate *GetPrimaryTraitOverride();
    eAlienRace GetRace();
    int GetStat(eFrigateStatType leStatType);
    const cGcFrigateTraitData *GetTrait(int liTraitIndex);
    void Invalidate();
    bool IsDamaged();
    void Load(const cGcPlayerFleetManager &lPlayerFleetManager, const cGcFleetFrigateSaveData &lSaveData);
    void OnCargoCollected(uint64_t lu64CollectionTime, int liAmountLeftBehind);
    void OnExpeditionComplete(int liNumberOfSuccesses, int liNumberOfFailures);
    void RepairDamagedBit(int liBitIndex);
    void Save(const cGcPlayerFleetManager &lPlayerFleetManager, cGcFleetFrigateSaveData &lSaveData);
    void SetAIShipSpawn(cGcAIShipSpawn *lpAIShipSpawn);
    void SetDamageTaken(char lDamageTaken);
    void SetDamaged(bool lbDamaged, const cTkSeed &lSeed, uint64_t lu64TimeOfDamage, bool lbCompletelyDamaged);
    void SetPirateDefensePlayer(const cGcPlayerCommon *lpPlayer, const cTkVector3 *lpSpawnPosition);
    void UpdateSpawnedShipDamageMaintenanceComponents();

    std::array<cGcFrigateTraitData const *, 5> maTraits;
    cTkVector<cGcMaintenanceComponent *> mapDamagedMaintenanceComponents;
    cTkVector3 mPirateDefenceSpawnPosition;
    uint64_t mu64TimeOfLastIncomeCollection;
    cTkAABB mAABB;
    cTkSeed mSeed;
    cTkSeed mHomeSystemSeed;
    cTkSeed mForcedTraitsSeed;
    cTkFixedString<32, char> mCustomName;
    eFrigateClass meFrigateClass;
    eInventoryClass meInventoryClass;
    eAlienRace meRace;
    TkID<128> mPrimaryTraitOverride;
    float mfTimeUntilSpawnEvent;
    int miTotalNumberOfSuccessfulEvents;
    int miTotalNumberOfFailedEvents;
    int miTotalNumberOfExpeditions;
    int miNumberOfTimesDamaged;
    int maiStats[11];
    cTkBitArray<uint64_t, true, 8> mDamageTaken;
    TkHandle mOnPlanetFalseFrigateNode;
    cGcAIShipSpawn *mpAIShipSpawn;
    const cGcPlayerCommon *mpPirateDefencePlayer;
    cTkAttachmentPtr mLODAttachment;
    cGcFleetExpedition *mpExpedition;
};

SKYSCRAPER_END