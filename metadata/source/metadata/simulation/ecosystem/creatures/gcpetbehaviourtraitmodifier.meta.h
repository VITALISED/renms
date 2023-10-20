#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcPetBehaviourTraitModifier
{
    static unsigned long long muNameHash = 0xE41D8EA9BE5AA4F8;
    static unsigned long long muTemplateHash = 0xF83BC00DCA9A3E83;

    cGcCreaturePetTraits Trait;
    float mfTraitMin;
    float mfTraitMax;
    float mfWeightModifierMin;
    float mfWeightModifierMax;
    float mfCooldownModifierMin;
    float mfCooldownModifierMax;
}
