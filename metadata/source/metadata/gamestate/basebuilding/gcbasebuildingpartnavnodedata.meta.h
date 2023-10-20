#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcBaseBuildingPartNavNodeData
{
    static unsigned long long muNameHash = 0xAE95337199B47CD;
    static unsigned long long muTemplateHash = 0xACE410E33E2B84B0;

    cGcNPCNavSubgraphNodeType Type;
    cTkVector3 mLocalPos;
    float mfArriveDist;
    cTkVector3 mAtDir;
    TkID<128> mInteractionID;
    cTkDynamicArray<unsigned int> maConnectedNodeIndices;
}
