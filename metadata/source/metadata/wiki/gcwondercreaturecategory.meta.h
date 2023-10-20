#pragma once
#include <metadata/metadata_common.h>
enum eWonderCreatureCategory
{
    EWonderCreatureCategory_HerbivoreSizeMax = 0,
    EWonderCreatureCategory_HerbivoreSizeMin = 1,
    EWonderCreatureCategory_CarnivoreSizeMax = 2,
    EWonderCreatureCategory_CarnivoreSizeMin = 3,
    EWonderCreatureCategory_IntelligenceMax = 4,
    EWonderCreatureCategory_ViciousnessMax = 5,
    EWonderCreatureCategory_Hot = 6,
    EWonderCreatureCategory_Cold = 7,
    EWonderCreatureCategory_Tox = 8,
    EWonderCreatureCategory_Rad = 9,
    EWonderCreatureCategory_Weird = 10,
    EWonderCreatureCategory_Water = 11,
    EWonderCreatureCategory_Robot = 12,
    EWonderCreatureCategory_Flyer = 13,
    EWonderCreatureCategory_Cave = 14,
}

class cGcWonderCreatureCategory
{
    static unsigned long long muNameHash = 0x11682D56DC3AFBF1;
    static unsigned long long muTemplateHash = 0x4C939A1F96BFC9A6;

    eWonderCreatureCategory WonderCreatureCategory;
}
