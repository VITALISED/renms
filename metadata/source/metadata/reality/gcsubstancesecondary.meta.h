#pragma once
#include <metadata/metadata_common.h>

class cGcSubstanceSecondary
{
    static unsigned long long muNameHash = 0xA655E8FCC4246967;
    static unsigned long long muTemplateHash = 0x8F872E8A3E7FBE8D;

    TkID<128> mID;
    float mfChance;
    float mfAmountMin;
    float mfAmountMax;
}
