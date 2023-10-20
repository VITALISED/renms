#pragma once
#include <metadata/metadata_common.h>

class cGcCreaturePetPartHider
{
    static unsigned long long muNameHash = 0xC7B26C36881B633D;
    static unsigned long long muTemplateHash = 0x966F62F2D6CC70A0;

    cTkFixedString<256,char> macAccessorySlot;
    cTkDynamicArray<TkID<256>> maPartName;
}
