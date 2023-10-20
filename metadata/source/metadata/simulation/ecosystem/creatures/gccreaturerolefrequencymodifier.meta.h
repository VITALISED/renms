#pragma once
#include <metadata/metadata_common.h>
enum eCreatureRoleFrequencyModifier
{
    ECreatureRoleFrequencyModifier_Never = 0,
    ECreatureRoleFrequencyModifier_Low = 1,
    ECreatureRoleFrequencyModifier_Normal = 2,
    ECreatureRoleFrequencyModifier_High = 3,
}

class cGcCreatureRoleFrequencyModifier
{
    static unsigned long long muNameHash = 0x8F2EED19BC2FFF5D;
    static unsigned long long muTemplateHash = 0x15D26A60973A874A;

    eCreatureRoleFrequencyModifier CreatureRoleFrequencyModifier;
}
