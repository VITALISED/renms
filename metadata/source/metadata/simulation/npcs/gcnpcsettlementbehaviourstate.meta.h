#pragma once
#include <metadata/metadata_common.h>
enum eNPCSettlementBehaviourState
{
    ENPCSettlementBehaviourState_Generic = 0,
    ENPCSettlementBehaviourState_Sociable = 1,
    ENPCSettlementBehaviourState_Productive = 2,
    ENPCSettlementBehaviourState_Tired = 3,
    ENPCSettlementBehaviourState_Afraid = 4,
}

class cGcNPCSettlementBehaviourState
{
    static unsigned long long muNameHash = 0x36730B94549148DE;
    static unsigned long long muTemplateHash = 0xCE0743B4909D405A;

    eNPCSettlementBehaviourState NPCSettlementBehaviourState;
}
