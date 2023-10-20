#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/ecosystem/creatures/data/gccreaturepettraits.meta.h>

class cGcPetEggTraitModifierOverrideData
{
    static unsigned long long muNameHash = 0xE14D5B0B53D91D7C;
    static unsigned long long muTemplateHash = 0x11259BB40F6BA697;

    TkID<128> mProductID;
    TkID<128> mSubstanceID;
    cGcCreaturePetTraits Trait;
    bool mbIncreasesTrait;
    int miBaseValueOverride;
}
