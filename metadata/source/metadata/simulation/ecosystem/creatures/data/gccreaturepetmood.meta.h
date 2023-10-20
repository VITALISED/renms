#pragma once
#include <metadata/metadata_common.h>
enum ePetMood
{
    EPetMood_Hungry = 0,
    EPetMood_Lonely = 1,
}

class cGcCreaturePetMood
{
    static unsigned long long muNameHash = 0x2581D5C5DE2A6E6;
    static unsigned long long muTemplateHash = 0xC92DB9B4AA0DC105;

    ePetMood PetMood;
}
