#pragma once
#include <metadata/metadata_common.h>

class cGcMinimumUseConstraint
{
    static unsigned long long muNameHash = 0xBA72D7FB7D17FABE;
    static unsigned long long muTemplateHash = 0xEEB2E8E5ED50946A;

    cTkDynamicArray<TkID<128>> maModules;
    int miMinUses;
    TkID<128> mGroup;
}
