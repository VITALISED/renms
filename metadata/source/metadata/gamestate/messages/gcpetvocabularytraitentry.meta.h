#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/ecosystem/creatures/data/gccreaturepettraits.meta.h>

class cGcPetVocabularyTraitEntry
{
    static unsigned long long muNameHash = 0xD1AA1B644B5DE736;
    static unsigned long long muTemplateHash = 0xA055504BF90A3AA6;

    cGcCreaturePetTraits Trait;
    TkID<256> mPositive;
    TkID<256> mNegative;
}
