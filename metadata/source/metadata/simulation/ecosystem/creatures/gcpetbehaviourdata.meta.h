#pragma once
#include <metadata/metadata_common.h>
enum ePetBehaviourValidity
{
    EPetBehaviourValidity_Everywhere = 0,
    EPetBehaviourValidity_OnPlanet = 1,
}
#include <?>
#include <?>
#include <?>

class cGcPetBehaviourData
{
    static unsigned long long muNameHash = 0x309337FC0812738C;
    static unsigned long long muTemplateHash = 0x285F130A426C7C92;

    bool mbReactiveBehaviour;
    bool mbUsefulBehaviour;
    float mfWeight;
    float mfMinPerformTime;
    float mfMaxPerformTime;
    float mfCooldownTime;
    float mfChatChance;
    float mfApproachPlayerDist;
    float mfSearchDist;
    ePetBehaviourValidity PetBehaviourValidity;
    cTkDynamicArray<cGcPetFollowUpBehaviour> maFollowUpBehaviours;
    cTkDynamicArray<cGcPetBehaviourTraitModifier> maTraitBehaviourModifiers;
    cTkDynamicArray<cGcPetBehaviourMoodModifier> maMoodBehaviourModifiers;
    cTkFixedArray<float> maMoodModifyOnComplete;
    TkID<256> mLabelText;
}
