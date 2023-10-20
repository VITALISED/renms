#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcPetTraitStaminaModifier
{
    static unsigned long long muNameHash = 0xDCD830657AF1993;
    static unsigned long long muTemplateHash = 0x5672F857EC49B2E6;

    cGcCreaturePetTraits Trait;
    float mfTraitMin;
    float mfTraitMax;
    float mfStaminaDrainModifierMin;
    float mfStaminaDrainModifierMax;
    float mfStaminaRechargeModifierMin;
    float mfStaminaRechargeModifierMax;
}
