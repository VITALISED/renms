/**
 * @file GcDifficultySettings.h
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

#include <reality/gcunlockabletreecosttype.meta.h>
#include <user/gcdifficultysettingenum.meta.h>
#include <user/gcdifficultystatedata.meta.h>

SKYSCRAPER_BEGIN

class cGcDifficultySettings
{
  public:
    enum ePresetMatchType;
    enum eCurrencyScalingMode;

    bool AreItemsDestroyedOnDeath();
    bool ArePurchasesWithCostTypeFree(eTypeOfCost leTypeOfCost, eCurrency leCurrency);
    cGcDifficultyPresetType CompareSettingDifficulty(
        const cGcDifficultySettingsData &lSettingsA, const cGcDifficultySettingsData &lSettingsB,
        eDifficultySetting leSetting);
    bool DoesSprintingDrainEnergy();
    void FillPersistentBaseDifficultyData(cGcPersistentBaseDifficultyData &lOutPersistentBaseData);
    float GetCurrencyCostMultiplier(
        eTypeOfCost leTypeOfCost, eCurrency leCurrency, cGcDifficultySettings::eCurrencyScalingMode leScalingMode,
        bool);
    cGcDifficultySettingsReplicatedState &GetReplicatedState();
    TkID<256> *GetSettingOptionLocIDs(eDifficultySetting leSetting, cTkVector<TkID<256>> &laOutOptionLocIDs);
    float GetSprintingRateMultipler();
    bool HasDifficultyAlwaysBeenAtPresetorHarder(eDifficultyPresetType leTestPreset);
    bool IsChargingFree();
    bool IsEnergyBarEnabled();
    bool IsFuelCheap();
    bool IsFuelFree();
    bool IsItemGraveSpawnedOnDeath();
    bool IsSaveDestroyedOnDeath();
    bool IsSprintingUnlimited();
    void Save(cGcDifficultyStateData &lStateData);
    float ScaleCurrencyCost(
        int liCost, cGcDifficultySettings::eCurrencyScalingMode leScalingMode, eTypeOfCost leTypeOfCost,
        eCurrency leCurrency, bool);
    void SetSettingsData(cGcDifficultySettingsData &lSettingsData);

    static cTkFixedString<64, char> &GetDifficultyIconStringInsert(const cGcNetworkPlayer *lpNetPlayer);
    static int FindMatchingPreset(
        cGcDifficultySettingsData &lSettingsData, cGcDifficultySettings::ePresetMatchType leMatchType);
    static int *GetOptionListSettingAsIntWritable(cGcDifficultySettingsData &lData, eDifficultySetting leSetting);
    static cGcDifficultyPresetType GetPresetForGameMode(ePresetGameMode leGameMode);
    static cGcDifficultySettingsData &GetPresetSettingsClampedByEditability(
        cGcDifficultySettingsData &lInCurrentSettings, eDifficultyPresetType leGameMode);
    static cGcDifficultySettingsData *GetToggleSettingWritable(
        cGcDifficultySettingsData &lData, eDifficultySetting leSetting);

    enum ePresetMatchType
    {
        EPresetMatchType_Exact,
        EPresetMatchType_WithinEditability,
    };

    enum ePresetRoundingDir
    {
        EPresetRoundingDir_Up,
        EPresetRoundingDir_Down,
    };

    enum eCurrencyScalingMode
    {
        ECurrencyScalingMode_DisplayedPrice,
        ECurrencyScalingMode_FinalTransaction,
    };

    cGcDifficultyStateData mDifficultyStateData;
    bool mbDifficultySettingsDirty;
};

SKYSCRAPER_END