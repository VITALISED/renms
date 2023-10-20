#pragma once
#include <metadata/metadata_common.h>
enum eRarity
{
    ERarity_Common = 0,
    ERarity_Uncommon = 1,
    ERarity_Rare = 2,
}

class cGcRarity
{
    static unsigned long long muNameHash = 0x85BD8B90D73C1D42;
    static unsigned long long muTemplateHash = 0x8E5033B6253D925C;

    eRarity Rarity;
}
