#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/npcs/gcnpcsettlementbehaviourentry.meta.h>

class cGcNPCSettlementBehaviourData
{
    static unsigned long long muNameHash = 0x87BC5043F293743D;
    static unsigned long long muTemplateHash = 0x59E06023F9468849;

    cGcNPCSettlementBehaviourEntry BaseBehaviour;
    cTkFixedArray<cGcNPCSettlementBehaviourEntry> maBehaviourOverrides;
}
