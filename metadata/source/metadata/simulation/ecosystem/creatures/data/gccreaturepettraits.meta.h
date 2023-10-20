#pragma once
#include <metadata/metadata_common.h>
enum ePetTrait
{
    EPetTrait_Helpfulness = 0,
    EPetTrait_Aggression = 1,
    EPetTrait_Independence = 2,
}

class cGcCreaturePetTraits
{
    static unsigned long long muNameHash = 0xA3FCF80E6002BE62;
    static unsigned long long muTemplateHash = 0x158E51018B850276;

    ePetTrait PetTrait;
}
