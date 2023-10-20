#pragma once
#include <metadata/metadata_common.h>

class cGcGeneratedBaseRoomTemplate
{
    static unsigned long long muNameHash = 0x11A53087B029E4F;
    static unsigned long long muTemplateHash = 0x3990C837CE0F70A1;

    TkID<128> mName;
    TkID<256> mLocId;
    cTkColour mPrimaryColour;
    cTkColour mSecondaryColour;
    cTkColour mTernaryColour;
    cTkColour mQuaternaryColour;
    int miMinPathLength;
    int miMaxPathLength;
    int miMinContiguousWidth;
    int miMinContiguousHeight;
    int miMinContiguousDepth;
    float mfShrinkFactor;
    cTkDynamicArray<TkID<128>> maDecorationThemes;
}
