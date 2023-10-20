#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>
#include <?>

class cGcShipAIAttackDataTable
{
    static unsigned long long muNameHash = 0xC501980088063B;
    static unsigned long long muTemplateHash = 0x6FB2E2B112C03148;

    cTkDynamicArray<cGcShipAICombatDefinition> maDefinitions;
    cTkDynamicArray<cGcShipAIAttackData> maBehaviourTable;
    cTkDynamicArray<cGcSpaceshipTravelData> maEngineTable;
    cTkDynamicArray<cGcSpaceshipShieldData> maShieldTable;
    cTkFixedArray<TkID<128>> maTraderAttackLookup;
}
