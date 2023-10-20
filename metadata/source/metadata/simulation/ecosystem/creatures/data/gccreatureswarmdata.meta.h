#pragma once
#include <metadata/metadata_common.h>
enum eSwarmMovementType
{
    ESwarmMovementType_None = 0,
    ESwarmMovementType_Circle = 1,
    ESwarmMovementType_Random = 2,
    ESwarmMovementType_Search = 3,
    ESwarmMovementType_FollowPlayer = 4,
    ESwarmMovementType_FollowPlayerLimited = 5,
}
#include <?>

class cGcCreatureSwarmData
{
    static unsigned long long muNameHash = 0x87C83AD7D0C1D117;
    static unsigned long long muTemplateHash = 0xB3AED157D9B5E63;

    int miMinCount;
    int miMaxCount;
    float mfSwarmMovementSpeed;
    float mfSwarmMovementRadius;
    eSwarmMovementType SwarmMovementType;
    cTkDynamicArray<cGcCreatureSwarmDataParams> maParams;
}
