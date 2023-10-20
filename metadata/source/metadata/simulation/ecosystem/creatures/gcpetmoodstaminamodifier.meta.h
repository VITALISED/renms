#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/ecosystem/creatures/data/gccreaturepetmood.meta.h>

class cGcPetMoodStaminaModifier
{
    static unsigned long long muNameHash = 0xE63B46A8CA0EF245;
    static unsigned long long muTemplateHash = 0x1DA5865B8E6F16CB;

    cGcCreaturePetMood Mood;
    float mfMoodMin;
    float mfMoodMax;
    float mfStaminaDrainModifierMin;
    float mfStaminaDrainModifierMax;
    float mfStaminaRechargeModifierMin;
    float mfStaminaRechargeModifierMax;
}
