#pragma once
#include <metadata/metadata_common.h>

class cGcLegacyItem
{
    static unsigned long long muNameHash = 0x132E24BDAE218C83;
    static unsigned long long muTemplateHash = 0x71FEDA0627F8F681;

    TkID<128> mID;
    TkID<128> mConvertID;
    float mfConvertRatio;
    bool mbAddNewRecipe;
    bool mbRemoveOldRecipe;
}
