#pragma once
#include <metadata/metadata_common.h>

class cGcCreatureEffectTrigger
{
    static unsigned long long muNameHash = 0x4E07F5FB46E3BD82;
    static unsigned long long muTemplateHash = 0xF2C93E6788CE0821;

    TkID<128> mEffect;
    cTkDynamicArray<cTkFixedString<256,char>> maJointName;
    float mfScale;
    TkID<128> mAnim;
    int miFrame;
    bool mbGroundTint;
}
