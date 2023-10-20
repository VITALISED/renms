#pragma once
#include <metadata/metadata_common.h>
enum eDifficultySetting
{
    EDifficultySetting_SettingsLocked = 0,
    EDifficultySetting_InventoriesAlwaysInRange = 1,
    EDifficultySetting_AllSlotsUnlocked = 2,
    EDifficultySetting_WarpDriveRequirements = 3,
    EDifficultySetting_CraftingIsFree = 4,
    EDifficultySetting_TutorialEnabled = 5,
    EDifficultySetting_StartWithAllItemsKnown = 6,
    EDifficultySetting_BaseAutoPower = 7,
    EDifficultySetting_DeathConsequences = 8,
    EDifficultySetting_DamageReceived = 9,
    EDifficultySetting_DamageGiven = 10,
    EDifficultySetting_ActiveSurvivalBars = 11,
    EDifficultySetting_HazardDrain = 12,
    EDifficultySetting_EnergyDrain = 13,
    EDifficultySetting_SubstanceCollection = 14,
    EDifficultySetting_InventoryStackLimits = 15,
    EDifficultySetting_ChargingRequirements = 16,
    EDifficultySetting_FuelUse = 17,
    EDifficultySetting_LaunchFuelCost = 18,
    EDifficultySetting_CurrencyCost = 19,
    EDifficultySetting_ScannerRecharge = 20,
    EDifficultySetting_ReputationGain = 21,
    EDifficultySetting_CreatureHostility = 22,
    EDifficultySetting_SpaceCombat = 23,
    EDifficultySetting_GroundCombat = 24,
    EDifficultySetting_ItemShopAvailablity = 25,
    EDifficultySetting_SprintingCost = 26,
    EDifficultySetting_BreakTechOnDamage = 27,
}

class cGcDifficultySettingEnum
{
    static unsigned long long muNameHash = 0x42FEEB238F6504DE;
    static unsigned long long muTemplateHash = 0x3697C286B1CD1B33;

    eDifficultySetting DifficultySetting;
}
