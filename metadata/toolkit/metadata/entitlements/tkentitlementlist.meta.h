#pragma once
#include <metadata/metadata_common.h>
#include <metadata/entitlements/tkentitlementlistdata.meta.h>

class cTkEntitlementList
{
    static unsigned long long muNameHash = 0x6DD030A653A9BBF2;
    static unsigned long long muTemplateHash = 0x436FB21FC7E1E24C;

    cTkDynamicArray<cTkEntitlementListData> maEntitlements;
}
