#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/projectiles/gcdamagemultiplier.meta.h>

class cGcDamageMultiplierLookup
{
    static unsigned long long muNameHash = 0x792FD0F5EBBA55E9;
    static unsigned long long muTemplateHash = 0x7C4E219CEB4F33C3;

    TkID<128> mId;
    float mfDefault;
    cTkDynamicArray<cGcDamageMultiplier> maMultipliers;
}
