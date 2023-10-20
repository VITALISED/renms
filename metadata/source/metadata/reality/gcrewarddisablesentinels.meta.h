#pragma once
#include <metadata/metadata_common.h>

class cGcRewardDisableSentinels
{
    static unsigned long long muNameHash = 0x231FFA8B84C504B1;
    static unsigned long long muTemplateHash = 0x800851CF8D9528D4;

    float mfDuration;
    TkID<256> mOSDMessage;
    TkID<256> mWantedBarMessage;
}
