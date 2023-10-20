#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/components/utils/gcbroadcastlevel.meta.h>

class cGcGoToStateAction
{
    static unsigned long long muNameHash = 0xBEE7641A87849DA4;
    static unsigned long long muTemplateHash = 0x935E6819AFDA899C;

    TkID<128> mState;
    bool mbBroadcast;
    cGcBroadcastLevel BroadcastLevel;
}
