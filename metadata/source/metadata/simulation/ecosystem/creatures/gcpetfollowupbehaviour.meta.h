#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cGcPetFollowUpBehaviour
{
    static unsigned long long muNameHash = 0xA03E661BB27C6E6A;
    static unsigned long long muTemplateHash = 0xD9E238B0102214C;

    cGcPetBehaviours Behaviour;
    bool mbTraitBased;
    cGcCreaturePetTraits Trait;
    float mfTraitMin;
    float mfTraitMax;
    float mfWeightMin;
    float mfWeightMax;
}
