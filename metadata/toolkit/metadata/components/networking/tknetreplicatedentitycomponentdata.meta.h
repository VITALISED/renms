#pragma once
#include <metadata/metadata_common.h>
enum eReplicationRange
{
    EReplicationRange_NotSet = 0,
    EReplicationRange_System = 1,
    EReplicationRange_SystemLocal = 2,
    EReplicationRange_Planet = 3,
    EReplicationRange_PlanetLocal = 4,
    EReplicationRange_Space = 5,
    EReplicationRange_SpaceStation = 6,
    EReplicationRange_Nexus = 7,
}
enum eSpawnType
{
    ESpawnType_Basic = 0,
    ESpawnType_Creature = 1,
}

class cTkNetReplicatedEntityComponentData
{
    static unsigned long long muNameHash = 0xDB0FD87A0597E5FD;
    static unsigned long long muTemplateHash = 0x4A0243DD40AA8081;

    cTkDynamicArray<cTkFixedString<128,char>> maReplicaComponentMask;
    eReplicationRange ReplicationRange;
    eSpawnType SpawnType;
    bool mbIgnoreComponents;
}
