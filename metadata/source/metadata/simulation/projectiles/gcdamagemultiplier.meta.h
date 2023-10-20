#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/projectiles/gcdamagetype.meta.h>

class cGcDamageMultiplier
{
    static unsigned long long muNameHash = 0xB387E3560FAA5681;
    static unsigned long long muTemplateHash = 0x6C8D917A23DA213F;

    cGcDamageType Type;
    float mfMultiplier;
}
