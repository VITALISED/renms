#pragma once
#include <metadata/metadata_common.h>
enum eProductCategory
{
    EProductCategory_Component = 0,
    EProductCategory_Consumable = 1,
    EProductCategory_Tradeable = 2,
    EProductCategory_Curiosity = 3,
    EProductCategory_BuildingPart = 4,
    EProductCategory_Procedural = 5,
    EProductCategory_Emote = 6,
    EProductCategory_CustomisationPart = 7,
    EProductCategory_CreatureEgg = 8,
}

class cGcProductCategory
{
    static unsigned long long muNameHash = 0xB3E1998DF67B4EF2;
    static unsigned long long muTemplateHash = 0xFD2D86AE268A7F24;

    eProductCategory ProductCategory;
}
