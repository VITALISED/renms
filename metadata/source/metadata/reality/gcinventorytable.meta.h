#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcinventorytableentry.meta.h>
#include <metadata/reality/gcinventorylayoutgenerationdata.meta.h>
#include <metadata/reality/gcinventorycostdata.meta.h>
#include <metadata/reality/gcinventorycostdataentry.meta.h>
#include <metadata/reality/gcinventoryclassprobabilities.meta.h>
#include <metadata/reality/gcinventorygenerationbasestatdata.meta.h>
#include <metadata/reality/gcinventorybasestat.meta.h>
#include <metadata/reality/gcshipinventorymaxupgradecapacity.meta.h>
#include <metadata/reality/gcweaponinventorymaxupgradecapacity.meta.h>

class cGcInventoryTable
{
    static unsigned long long muNameHash = 0x32822FA2FD268A65;
    static unsigned long long muTemplateHash = 0x9D2794859AD00F81;

    cTkDynamicArray<cGcInventoryTableEntry> maTable;
    cGcInventoryLayoutGenerationData GenerationData;
    cGcInventoryCostData ShipCostData;
    cTkFixedArray<cGcInventoryCostDataEntry> maWeaponCostData;
    cGcInventoryCostDataEntry VehicleCostData;
    cTkFixedArray<cGcInventoryClassProbabilities> maClassProbabilityData;
    cGcInventoryGenerationBaseStatData VehicleBaseStatsData;
    cTkFixedArray<cGcInventoryGenerationBaseStatData> maShipBaseStatsData;
    cTkFixedArray<cGcInventoryGenerationBaseStatData> maWeaponBaseStatsData;
    cTkDynamicArray<cGcInventoryBaseStat> maBaseStats;
    cTkFixedArray<cGcShipInventoryMaxUpgradeCapacity> maShipInventoryMaxUpgradeSize;
    cGcWeaponInventoryMaxUpgradeCapacity WeaponInventoryMaxUpgradeSize;
}
