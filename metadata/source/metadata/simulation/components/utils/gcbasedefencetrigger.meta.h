#pragma once
#include <metadata/metadata_common.h>

class cGcBaseDefenceTrigger
{
    static unsigned long long muNameHash = 0x295BE0CF9BD70B66;
    static unsigned long long muTemplateHash = 0xCBDA352215D0A296;

    TkID<128> mPerceptionId;
    bool mbActiveWhenIdle;
    bool mbActiveWhenTargetAcquired;
    bool mbActiveWhenSearching;
    TkID<128> mLaserEffectId;
}
