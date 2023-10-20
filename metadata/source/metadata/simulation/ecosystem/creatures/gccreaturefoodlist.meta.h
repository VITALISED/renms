#pragma once
#include <metadata/metadata_common.h>

class cGcCreatureFoodList
{
    static unsigned long long muNameHash = 0x8FD3FE17A0260717;
    static unsigned long long muTemplateHash = 0xBC20E05A80B75CA6;

    TkID<128> mFoodProduct;
    cTkFixedString<128,char> macResourceFile;
    TkID<128> mDebrisEffect;
}
