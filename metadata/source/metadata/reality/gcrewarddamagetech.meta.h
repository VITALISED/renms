#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gctechnologycategory.meta.h>

class cGcRewardDamageTech
{
    static unsigned long long muNameHash = 0x7DA0241C104EEDF;
    static unsigned long long muTemplateHash = 0xC1EDE759697D3725;

    cGcTechnologyCategory Category;
    TkID<128> mTechToDamage_optional;
    bool mbShowDamageMessage;
}
