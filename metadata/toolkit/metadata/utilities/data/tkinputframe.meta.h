#pragma once
#include <metadata/metadata_common.h>

class cTkInputFrame
{
    static unsigned long long muNameHash = 0xF3DC604B80A24AD;
    static unsigned long long muTemplateHash = 0xFEBE52C18D488494;

    cTkVector2 mLeftStick;
    cTkVector2 mRightStick;
    float mfLeftTrigger;
    float mfRightTrigger;
    short miButtons;
}
