#pragma once
#include <metadata/metadata_common.h>
enum eImpact
{
    EImpact_Default = 0,
    EImpact_Terrain = 1,
    EImpact_Substance = 2,
    EImpact_Rock = 3,
    EImpact_Asteroid = 4,
    EImpact_Shield = 5,
    EImpact_Creature = 6,
    EImpact_Robot = 7,
    EImpact_Freighter = 8,
    EImpact_Cargo = 9,
    EImpact_Ship = 10,
    EImpact_Plant = 11,
    EImpact_NeedsTech = 12,
    EImpact_Player = 13,
    EImpact_OtherPlayer = 14,
    EImpact_SentinelShield = 15,
    EImpact_SpaceshipShield = 16,
}

class cGcProjectileImpactType
{
    static unsigned long long muNameHash = 0xC652A220FFABA4FE;
    static unsigned long long muTemplateHash = 0x4B2046067B91DF22;

    eImpact Impact;
}
