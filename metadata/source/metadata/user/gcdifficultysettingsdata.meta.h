#pragma once
#include <metadata/metadata_common.h>
#include <metadata/user/gcdeathconsequencesdifficultyoption.meta.h>
#include <metadata/user/gcdamagereceiveddifficultyoption.meta.h>
#include <metadata/user/gcdamagegivendifficultyoption.meta.h>
#include <metadata/user/gcactivesurvivalbarsdifficultyoption.meta.h>
#include <metadata/user/gchazarddraindifficultyoption.meta.h>
#include <metadata/user/gcenergydraindifficultyoption.meta.h>
#include <metadata/user/gcsubstancecollectiondifficultyoption.meta.h>
#include <metadata/user/gcinventorystacklimitsdifficultyoption.meta.h>
#include <metadata/user/gcchargingrequirementsdifficultyoption.meta.h>
#include <metadata/user/gcfuelusedifficultyoption.meta.h>
#include <metadata/user/gclaunchfuelcostdifficultyoption.meta.h>
#include <metadata/user/gccurrencycostdifficultyoption.meta.h>
#include <metadata/user/gcitemshopavailabilitydifficultyoption.meta.h>
#include <metadata/user/gcscannerrechargedifficultyoption.meta.h>
#include <metadata/user/gcreputationgaindifficultyoption.meta.h>
#include <metadata/user/gccreaturehostilitydifficultyoption.meta.h>
#include <metadata/user/gccombattimerdifficultyoption.meta.h>
#include <metadata/user/gcsprintingcostdifficultyoption.meta.h>
#include <metadata/user/gcbreaktechondamagedifficultyoption.meta.h>

class cGcDifficultySettingsData
{
    static unsigned long long muNameHash = 0x640D4FDC2A95A771;
    static unsigned long long muTemplateHash = 0x26F84C6D1073784E;

    bool mbSettingsLocked;
    bool mbInventoriesAlwaysInRange;
    bool mbAllSlotsUnlocked;
    bool mbWarpDriveRequirements;
    bool mbCraftingIsFree;
    bool mbTutorialEnabled;
    bool mbStartWithAllItemsKnown;
    bool mbBaseAutoPower;
    cGcDeathConsequencesDifficultyOption DeathConsequences;
    cGcDamageReceivedDifficultyOption DamageReceived;
    cGcDamageGivenDifficultyOption DamageGiven;
    cGcActiveSurvivalBarsDifficultyOption ActiveSurvivalBars;
    cGcHazardDrainDifficultyOption HazardDrain;
    cGcEnergyDrainDifficultyOption EnergyDrain;
    cGcSubstanceCollectionDifficultyOption SubstanceCollection;
    cGcInventoryStackLimitsDifficultyOption InventoryStackLimits;
    cGcChargingRequirementsDifficultyOption ChargingRequirements;
    cGcFuelUseDifficultyOption FuelUse;
    cGcLaunchFuelCostDifficultyOption LaunchFuelCost;
    cGcCurrencyCostDifficultyOption CurrencyCost;
    cGcItemShopAvailabilityDifficultyOption ItemShopAvailability;
    cGcScannerRechargeDifficultyOption ScannerRecharge;
    cGcReputationGainDifficultyOption ReputationGain;
    cGcCreatureHostilityDifficultyOption CreatureHostility;
    cGcCombatTimerDifficultyOption SpaceCombatTimers;
    cGcCombatTimerDifficultyOption GroundCombatTimers;
    cGcSprintingCostDifficultyOption SprintingCost;
    cGcBreakTechOnDamageDifficultyOption BreakTechOnDamage;
}
