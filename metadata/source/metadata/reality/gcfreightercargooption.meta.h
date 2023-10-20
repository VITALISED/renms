#pragma once
#include <metadata/metadata_common.h>

class cGcFreighterCargoOption
{
    static unsigned long long muNameHash = 0xAEE2DF0976A04EB1;
    static unsigned long long muTemplateHash = 0x9540F9F46EDC3C9F;

    TkID<128> mID;
    int miMinAmount;
    int miMaxAmount;
    int miPercentChance;
}
