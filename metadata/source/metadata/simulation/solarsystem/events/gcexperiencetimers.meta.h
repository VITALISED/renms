#pragma once
#include <metadata/metadata_common.h>

class cGcExperienceTimers
{
    static unsigned long long muNameHash = 0x7DF5AD147C5460A0;
    static unsigned long long muTemplateHash = 0xF7EAE5E8DD0CF3F7;

    int miHighChance;
    int miLowChance;
    cTkVector2 mHigh;
    cTkVector2 mNormal;
    cTkVector2 mLow;
}
