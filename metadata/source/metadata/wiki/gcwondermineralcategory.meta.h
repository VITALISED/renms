#pragma once
#include <metadata/metadata_common.h>
enum eWonderMineralCategory
{
    EWonderMineralCategory_GeneralFact0 = 0,
    EWonderMineralCategory_GeneralFact1 = 1,
    EWonderMineralCategory_GeneralFact2 = 2,
    EWonderMineralCategory_MetalFact = 3,
    EWonderMineralCategory_ColdFact = 4,
    EWonderMineralCategory_HotFact = 5,
    EWonderMineralCategory_RadFact = 6,
    EWonderMineralCategory_ToxFact = 7,
}

class cGcWonderMineralCategory
{
    static unsigned long long muNameHash = 0x9B7B2957FC905892;
    static unsigned long long muTemplateHash = 0xBB5B13115C4843E7;

    eWonderMineralCategory WonderMineralCategory;
}
