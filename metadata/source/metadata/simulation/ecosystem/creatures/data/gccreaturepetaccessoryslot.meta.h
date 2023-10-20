#pragma once
#include <metadata/metadata_common.h>

class cGcCreaturePetAccessorySlot
{
    static unsigned long long muNameHash = 0x7A3E98EFAB95FF53;
    static unsigned long long muTemplateHash = 0x2670BF9C30F864C0;

    cTkFixedString<256,char> macAttachLocator;
    TkID<128> mAccessoryGroup;
}
