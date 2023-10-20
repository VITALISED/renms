#pragma once
#include <metadata/metadata_common.h>
enum eGeneratorUnitType
{
    EGeneratorUnitType_MiningUnit = 0,
    EGeneratorUnitType_GasHarvester = 1,
    EGeneratorUnitType_SystemHoover = 2,
}
#include <?>

class cGcGeneratorUnitComponentData
{
    static unsigned long long muNameHash = 0xE7D049A3A9D077A8;
    static unsigned long long muTemplateHash = 0xFB38EAEFCC344295;

    eGeneratorUnitType GeneratorUnitType;
    int miResourceMaintenanceSlotOverride;
    cTkFixedArray<TkID<128>> maBiomeGasRewards;
    cGcMaintenanceComponentData MaintenanceData;
}
