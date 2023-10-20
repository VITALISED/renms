#pragma once
#include <metadata/metadata_common.h>
enum eNPCSettlementBehaviourAreaProperty
{
    ENPCSettlementBehaviourAreaProperty_ContainsPlayer = 0,
    ENPCSettlementBehaviourAreaProperty_ContainsNPCs = 1,
}

class cGcNPCSettlementBehaviourAreaProperty
{
    static unsigned long long muNameHash = 0x402D87044A8D02D3;
    static unsigned long long muTemplateHash = 0x58744973BB15A41F;

    eNPCSettlementBehaviourAreaProperty NPCSettlementBehaviourAreaProperty;
}
