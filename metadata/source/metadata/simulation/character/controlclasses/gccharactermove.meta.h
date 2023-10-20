#pragma once
#include <metadata/metadata_common.h>
enum eMode
{
    EMode_SetVelocity = 0,
    EMode_ApplyForce = 1,
}

class cGcCharacterMove
{
    static unsigned long long muNameHash = 0x7E96F40C0051D69C;
    static unsigned long long muTemplateHash = 0x69D4C6F5C5341C1B;

    TkID<128> mInput;
    float mfStrength;
    eMode Mode;
}
