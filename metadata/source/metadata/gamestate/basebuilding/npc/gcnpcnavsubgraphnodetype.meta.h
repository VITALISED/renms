#pragma once
#include <metadata/metadata_common.h>
enum eNPCNavSubgraphNodeType
{
    ENPCNavSubgraphNodeType_Path = 0,
    ENPCNavSubgraphNodeType_Connection = 1,
    ENPCNavSubgraphNodeType_PointOfInterest = 2,
}

class cGcNPCNavSubgraphNodeType
{
    static unsigned long long muNameHash = 0xBFFCA397C2DEA0EE;
    static unsigned long long muTemplateHash = 0x5198BF8A16C55353;

    eNPCNavSubgraphNodeType NPCNavSubgraphNodeType;
}
