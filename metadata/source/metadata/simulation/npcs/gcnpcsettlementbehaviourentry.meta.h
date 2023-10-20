#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/npcs/gcnpcsettlementbehaviourbuildingclasscapacityentry.meta.h>
#include <metadata/simulation/npcs/gcnpcsettlementbehaviourareapropertyweightentry.meta.h>
#include <metadata/simulation/npcs/gcnpcsettlementbehaviourbuildingclassweightentry.meta.h>
#include <metadata/simulation/npcs/gcnpcsettlementbehaviourobjecttypeweightentry.meta.h>

class cGcNPCSettlementBehaviourEntry
{
    static unsigned long long muNameHash = 0xB268E74AC135A1A5;
    static unsigned long long muTemplateHash = 0xDC67D89D62DABC7C;

    float mfRunWhenOutdoorsProbability;
    bool mbOnlyUseIndoorPOIs;
    cTkDynamicArray<cGcNPCSettlementBehaviourBuildingClassCapacityEntry> maBuildingClassCapacities;
    cTkDynamicArray<cGcNPCSettlementBehaviourAreaPropertyWeightEntry> maAreaPropertyWeights;
    cTkDynamicArray<cGcNPCSettlementBehaviourBuildingClassWeightEntry> maBuildingClassWeights;
    cTkDynamicArray<cGcNPCSettlementBehaviourObjectTypeWeightEntry> maObjectTypeWeights;
}
