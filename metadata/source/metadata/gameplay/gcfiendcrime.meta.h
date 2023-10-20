#pragma once
#include <metadata/metadata_common.h>
enum eFiendCrime
{
    EFiendCrime_None = 0,
    EFiendCrime_EggDamaged = 1,
    EFiendCrime_EggDestroyed = 2,
    EFiendCrime_EggCollected = 3,
    EFiendCrime_UnderwaterPropDamaged = 4,
    EFiendCrime_UnderwaterPropCollected = 5,
    EFiendCrime_RockTransform = 6,
    EFiendCrime_GroundPropDamage = 7,
    EFiendCrime_ShotWorm = 8,
}

class cGcFiendCrime
{
    static unsigned long long muNameHash = 0xAF90A56B0E99C0CB;
    static unsigned long long muTemplateHash = 0x6F5426522A182A53;

    eFiendCrime FiendCrime;
}
