#pragma once
#include <metadata/metadata_common.h>

class cGcSavedEntitlement
{
    static unsigned long long muNameHash = 0xCEE0D0F77485755F;
    static unsigned long long muTemplateHash = 0xEB6CA826D9390F53;

    cTkFixedString<256,char> macEntitlementId;
}
