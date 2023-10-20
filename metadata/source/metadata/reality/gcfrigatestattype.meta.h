#pragma once
#include <metadata/metadata_common.h>
enum eFrigateStatType
{
    EFrigateStatType_Combat = 0,
    EFrigateStatType_Exploration = 1,
    EFrigateStatType_Mining = 2,
    EFrigateStatType_Diplomatic = 3,
    EFrigateStatType_FuelBurnRate = 4,
    EFrigateStatType_FuelCapacity = 5,
    EFrigateStatType_Speed = 6,
    EFrigateStatType_ExtraLoot = 7,
    EFrigateStatType_Repair = 8,
    EFrigateStatType_Invulnerable = 9,
    EFrigateStatType_Stealth = 10,
}

class cGcFrigateStatType
{
    static unsigned long long muNameHash = 0x5B21B72DF30D668C;
    static unsigned long long muTemplateHash = 0xA354D70279797182;

    eFrigateStatType FrigateStatType;
}
