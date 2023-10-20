#pragma once
#include <metadata/metadata_common.h>

class cGcMissionSequenceGetUnitsToBuyItem
{
    static unsigned long long muNameHash = 0x9DE374680DE23364;
    static unsigned long long muTemplateHash = 0xBA4647DFD2FF9EC6;

    cTkFixedString<128,char> macMessage;
    TkID<128> mItem;
    cTkFixedString<128,char> macDebugText;
}
