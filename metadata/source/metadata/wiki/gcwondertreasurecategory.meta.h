#pragma once
#include <metadata/metadata_common.h>
enum eWonderTreasureCategory
{
    EWonderTreasureCategory_Loot = 0,
    EWonderTreasureCategory_Document = 1,
    EWonderTreasureCategory_BioSample = 2,
    EWonderTreasureCategory_Fossil = 3,
    EWonderTreasureCategory_Plant = 4,
    EWonderTreasureCategory_Tool = 5,
    EWonderTreasureCategory_Farm = 6,
    EWonderTreasureCategory_SeaLoot = 7,
    EWonderTreasureCategory_SeaHorror = 8,
    EWonderTreasureCategory_Salvage = 9,
    EWonderTreasureCategory_Bones = 10,
    EWonderTreasureCategory_SpaceHorror = 11,
    EWonderTreasureCategory_SpaceBones = 12,
}

class cGcWonderTreasureCategory
{
    static unsigned long long muNameHash = 0x541D78BA92E4C104;
    static unsigned long long muTemplateHash = 0x786DE8497EEECF6E;

    eWonderTreasureCategory WonderTreasureCategory;
}
