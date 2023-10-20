#pragma once
#include <metadata/metadata_common.h>
enum eTechnologyRarity
{
    ETechnologyRarity_Normal = 0,
    ETechnologyRarity_VeryCommon = 1,
    ETechnologyRarity_Common = 2,
    ETechnologyRarity_Rare = 3,
    ETechnologyRarity_VeryRare = 4,
    ETechnologyRarity_Impossible = 5,
    ETechnologyRarity_Always = 6,
}

class cGcTechnologyRarity
{
    static unsigned long long muNameHash = 0xDB3D22C1C68F20C3;
    static unsigned long long muTemplateHash = 0x39B9A7A9078A0304;

    eTechnologyRarity TechnologyRarity;
}
