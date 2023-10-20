#pragma once
#include <metadata/metadata_common.h>

class cGcRewardDisplayTechWindow
{
    static unsigned long long muNameHash = 0xC04EFF3E2A378ED7;
    static unsigned long long muTemplateHash = 0xF588B1A7241558D0;

    TkID<128> mTechID;
    bool mbDamaged;
    bool mbNeedsInstall;
    bool mbFullBox;
}
