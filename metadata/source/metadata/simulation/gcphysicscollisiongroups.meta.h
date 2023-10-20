#pragma once
#include <metadata/metadata_common.h>
enum eCollisionGroup
{
    ECollisionGroup_Normal = 1,
    ECollisionGroup_Water = 2,
    ECollisionGroup_Terrain = 4,
    ECollisionGroup_Substance = 8,
    ECollisionGroup_Asteroid = 16,
    ECollisionGroup_TerrainInstance = 32,
    ECollisionGroup_TerrainActivated = 64,
    ECollisionGroup_Player = 128,
    ECollisionGroup_Creature = 256,
    ECollisionGroup_Spaceship = 512,
    ECollisionGroup_Debris = 1024,
    ECollisionGroup_Shield = 2048,
    ECollisionGroup_Raycast = 4096,
    ECollisionGroup_NetworkPlayer = 8192,
    ECollisionGroup_NPCs = 16384,
    ECollisionGroup_Trigger = 32768,
}

class cGcPhysicsCollisionGroups
{
    static unsigned long long muNameHash = 0x29A5D23AA5A4C794;
    static unsigned long long muTemplateHash = 0x33871F8C1A70C814;

    eCollisionGroup CollisionGroup;
}
