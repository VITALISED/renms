#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>
#include <?>

class cGcDifficultyConfig
{
    static unsigned long long muNameHash = 0xA688E4255C8FED76;
    static unsigned long long muTemplateHash = 0x24D7B6A525FF59C4;

    TkID<256> mPresetLocId;
    cTkFixedArray<TkID<256>> maPresetOptionLocIds;
    cTkFixedArray<cGcDifficultySettingsData> maPresets;
    cGcDifficultySettingsData PermadeathMinSettings;
    cTkFixedArray<cGcDifficultyOptionUIGroup> maUILayout;
    cTkFixedArray<cGcDifficultySettingCommonData> maCommonSettingsData;
    int miAllSlotsUnlockedStartingSuitSlots;
    int miAllSlotsUnlockedStartingSuitTechSlots;
    int miAllSlotsUnlockedStartingWeaponSlots;
    int miAllSlotsUnlockedStartingShipSlots;
    int miAllSlotsUnlockedStartingShipTechSlots;
    cGcDifficultyStartWithAllItemsKnownOptionData StartWithAllItemsKnownDisabledData;
    cGcDifficultyStartWithAllItemsKnownOptionData StartWithAllItemsKnownEnabledData;
    cTkFixedArray<TkID<256>> maCreatureHostilityOptionLocIds;
    cTkFixedArray<TkID<256>> maDeathConsequencesOptionLocIds;
    cTkFixedArray<TkID<256>> maDamageReceivedOptionLocIds;
    cTkFixedArray<float> maDamageReceivedMultipliers;
    cTkFixedArray<int> maDamageReceivedAIMechTechDamageHits;
    cTkFixedArray<TkID<256>> maDamageGivenOptionLocIds;
    cTkFixedArray<float> maDamageGivenMultipliers;
    cTkFixedArray<TkID<256>> maActiveSurvivalBarsOptionLocIds;
    cTkFixedArray<TkID<256>> maHazardDrainOptionLocIds;
    cTkFixedArray<float> maHazardDrainMultipliers;
    cTkFixedArray<TkID<256>> maEnergyDrainOptionLocIds;
    cTkFixedArray<float> maEnergyDrainMultipliers;
    cTkFixedArray<TkID<256>> maSubstanceCollectionOptionLocIds;
    cTkFixedArray<float> maSubstanceCollectionMultipliers;
    cTkFixedArray<int> maSubstanceCollectionLaserAmount;
    cTkFixedArray<TkID<256>> maInventoryStackLimitsOptionLocIds;
    cTkFixedArray<cGcDifficultyInventoryStackSizeOptionData> maInventoryStackLimitsOptionData;
    cTkFixedArray<TkID<256>> maChargingRequirementsOptionLocIds;
    cTkFixedArray<float> maChargingRequirementsMultipliers;
    cTkFixedArray<TkID<256>> maFuelUseOptionLocIds;
    cTkFixedArray<cGcDifficultyFuelUseOptionData> maFuelUseOptionData;
    cTkFixedArray<TkID<256>> maLaunchFuelCostOptionLocIds;
    cTkFixedArray<float> maLaunchFuelCostMultipliers;
    cTkFixedArray<float> maShipSummoningFuelCostMultipliers;
    cTkFixedArray<TkID<256>> maCurrencyCostOptionLocIds;
    cTkFixedArray<cGcDifficultyCurrencyCostOptionData> maCurrencyCostOptionData;
    cTkFixedArray<TkID<256>> maItemShopAvailabilityOptionLocIds;
    cTkFixedArray<cGcItemShopAvailabilityDifficultyOptionData> maItemShopAvailabilityOptionData;
    cTkFixedArray<TkID<256>> maScannerRechargeOptionLocIds;
    cTkFixedArray<float> maScannerRechargeMultipliers;
    cTkFixedArray<TkID<256>> maReputationGainOptionLocIds;
    cTkFixedArray<float> maReputationGainMultipliers;
    cTkFixedArray<TkID<256>> maSpaceCombatOptionLocIds;
    cTkFixedArray<float> maSpaceCombatMultipliers;
    cTkFixedArray<float> maSpaceCombatDifficultyMultipliers;
    cTkFixedArray<TkID<256>> maGroundCombatOptionLocIds;
    cTkFixedArray<float> maGroundCombatMultipliers;
    cTkFixedArray<float> maSentinelTimeOutMultipliers;
    cTkFixedArray<TkID<256>> maSprintingOptionLocIds;
    cTkFixedArray<float> maSprintingCostMultipliers;
    cTkFixedArray<TkID<256>> maBreakTechOnDamageOptionLocIds;
    cTkFixedArray<float> maBreakTechOnDamageMultipliers;
}
