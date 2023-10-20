#pragma once
#include <metadata/metadata_common.h>

class cGcEntitlementRewardData
{
    static unsigned long long muNameHash = 0x748EDC86AFA4F5A3;
    static unsigned long long muTemplateHash = 0x6A88D23C53219B88;

    TkID<128> mEntitlementId;
    TkID<128> mRewardId;
    TkID<256> mName;
    TkID<256> mError;
}
