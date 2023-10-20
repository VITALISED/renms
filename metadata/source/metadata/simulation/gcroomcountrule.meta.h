#pragma once
#include <metadata/metadata_common.h>

class cGcRoomCountRule
{
    static unsigned long long muNameHash = 0x847F4524E9703A38;
    static unsigned long long muTemplateHash = 0x1AB7E133476CBD7;

    TkID<128> mRoomID;
    int miMin;
    int miMax;
}
