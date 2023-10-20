#pragma once
#include <metadata/metadata_common.h>

class cGcMissionSequenceRepairTech
{
    static unsigned long long muNameHash = 0xF83A832D3507037F;
    static unsigned long long muTemplateHash = 0x968BA03C12A75A61;

    cTkFixedString<128,char> macMessage;
    cTkDynamicArray<TkID<128>> maTechsToRepair;
    cTkFixedString<128,char> macDebugText;
}
