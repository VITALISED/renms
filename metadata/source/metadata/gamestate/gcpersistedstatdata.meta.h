#pragma once
#include <metadata/metadata_common.h>

class cGcPersistedStatData
{
    static unsigned long long muNameHash = 0x8A1BFCC09E50150B;
    static unsigned long long muTemplateHash = 0xBEDC2ADA39713304;

    TkID<128> mGroupId;
    TkID<128> mStatId;
}
