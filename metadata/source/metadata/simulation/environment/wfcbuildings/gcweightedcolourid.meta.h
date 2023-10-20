#pragma once
#include <metadata/metadata_common.h>

class cGcWeightedColourId
{
    static unsigned long long muNameHash = 0x8C8D94961F3707E0;
    static unsigned long long muTemplateHash = 0x2044DDAFDFD83869;

    float mfRelativeProbability;
    TkID<256> mPalette;
    TkID<256> mDecorationPalette;
}
