#pragma once
#include <metadata/metadata_common.h>

class cGcRewardOpenFreeFreighter
{
    static unsigned long long muNameHash = 0x4DD6C74BA4B6AD5A;
    static unsigned long long muTemplateHash = 0xD215FE9145145C73;

    bool mbReinteractWhenBought;
    TkID<256> mNextInteractionIfBought;
    TkID<256> mNextInteractionIfNotBought;
}
