#pragma once
#include <metadata/metadata_common.h>

class cGcRewardUnlockTitle
{
    static unsigned long long muNameHash = 0xAC19C9A74178EED8;
    static unsigned long long muTemplateHash = 0x9886B628740CE568;

    TkID<128> mTitleID;
    bool mbNoMusic;
    bool mbShowEvenIfAlreadyUnlocked;
}
