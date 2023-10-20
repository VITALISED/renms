#pragma once
#include <metadata/metadata_common.h>
enum eWonderFloraCategory
{
    EWonderFloraCategory_GeneralFact0 = 0,
    EWonderFloraCategory_GeneralFact1 = 1,
    EWonderFloraCategory_GeneralFact2 = 2,
    EWonderFloraCategory_GeneralFact3 = 3,
    EWonderFloraCategory_ColdFact = 4,
    EWonderFloraCategory_HotFact = 5,
    EWonderFloraCategory_RadFact = 6,
    EWonderFloraCategory_ToxFact = 7,
}

class cGcWonderFloraCategory
{
    static unsigned long long muNameHash = 0x5AC5BEA036002DC;
    static unsigned long long muTemplateHash = 0x5FABE5DB17A678A5;

    eWonderFloraCategory WonderFloraCategory;
}
