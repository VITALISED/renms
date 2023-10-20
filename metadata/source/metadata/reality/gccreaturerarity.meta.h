#pragma once
#include <metadata/metadata_common.h>
enum eCreatureRarity
{
    ECreatureRarity_Common = 0,
    ECreatureRarity_Uncommon = 1,
    ECreatureRarity_Rare = 2,
    ECreatureRarity_SuperRare = 3,
}

class cGcCreatureRarity
{
    static unsigned long long muNameHash = 0x5FD144DDEE5E5ECF;
    static unsigned long long muTemplateHash = 0x7AFDCAB459BF6B79;

    eCreatureRarity CreatureRarity;
}
