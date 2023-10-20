#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/ecosystem/creatures/gcpetbehaviourdata.meta.h>
#include <metadata/simulation/ecosystem/creatures/gcpettraitmoodmodifierlist.meta.h>
#include <metadata/simulation/ecosystem/creatures/gcpetactionmoodmodifier.meta.h>
#include <metadata/simulation/ecosystem/creatures/data/gccreaturepettraitranges.meta.h>
#include <metadata/simulation/ecosystem/creatures/gcpettraitstaminamodifier.meta.h>
#include <metadata/simulation/ecosystem/creatures/gcpetmoodstaminamodifier.meta.h>

class cGcPetBehaviourTable
{
    static unsigned long long muNameHash = 0x39BD1ED2FC8D7524;
    static unsigned long long muTemplateHash = 0x78F621A5B62DEA07;

    cTkFixedArray<cGcPetBehaviourData> maBehaviours;
    float mfGlobalCooldownModifier;
    float mfUsefulBehaviourLinkedCooldownAmount;
    float mfPlayerActivityIncreaseTime;
    float mfPlayerActivityDecreaseTime;
    cTkFixedArray<float> maMoodIncreaseTime;
    cTkFixedArray<cGcPetTraitMoodModifierList> maTraitMoodModifiers;
    cTkFixedArray<cGcPetActionMoodModifier> maRewardMoodModifier;
    cTkFixedArray<cGcCreaturePetTraitRanges> maTraitRanges;
    cTkFixedArray<float> maMoodValuesOnAdopt;
    cTkFixedArray<float> maMoodValuesOnHatch;
    cTkDynamicArray<cGcPetTraitStaminaModifier> maTraitStaminaModifiers;
    cTkDynamicArray<cGcPetMoodStaminaModifier> maMoodStaminaModifiers;
    float mfAccessoryGyroFollowMotionStrength;
    float mfAccessoryGyroToNeutralStrength;
    float mfAccessoryGyroDamping;
    float mfAccessoryGyroStrength;
    bool mbAccessoryGyroActive;
}
