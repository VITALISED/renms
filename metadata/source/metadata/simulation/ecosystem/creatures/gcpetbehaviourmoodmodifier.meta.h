#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcPetBehaviourMoodModifier
{
    static unsigned long long muNameHash = 0x7665E5534F420118;
    static unsigned long long muTemplateHash = 0x8D3E77D7F2B1C8B2;

    cGcCreaturePetMood Mood;
    float mfMoodMin;
    float mfMoodMax;
    float mfWeightModifierMin;
    float mfWeightModifierMax;
    float mfCooldownModifierMin;
    float mfCooldownModifierMax;
}
