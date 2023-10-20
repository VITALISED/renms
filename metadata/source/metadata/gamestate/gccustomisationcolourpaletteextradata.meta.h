#pragma once
#include <metadata/metadata_common.h>

class cGcCustomisationColourPaletteExtraData
{
    static unsigned long long muNameHash = 0x9B0B9933C035E4C2;
    static unsigned long long muTemplateHash = 0xD4665C5C1C4BCE67;

    cTkDynamicArray<TkID<128>> maProductToUnlock;
    cTkDynamicArray<TkID<256>> maTipText;
}
