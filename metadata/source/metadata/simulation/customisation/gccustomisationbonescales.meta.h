#pragma once
#include <metadata/metadata_common.h>

class cGcCustomisationBoneScales
{
    static unsigned long long muNameHash = 0x79EA3335C4095B8E;
    static unsigned long long muTemplateHash = 0xBB9FCA6782A31A70;

    TkID<256> mGroupTitle;
    TkID<128> mScaleBoneName;
    cTkDynamicArray<float> maPositions;
}
