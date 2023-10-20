#pragma once
#include <metadata/metadata_common.h>

class cTkEntitlementListData
{
    static unsigned long long muNameHash = 0x7D0C84AE84B756D5;
    static unsigned long long muTemplateHash = 0x5D44992908864ABF;

    TkID<128> mEntitlementId;
    cTkFixedString<64,char> macServiceID;
}
