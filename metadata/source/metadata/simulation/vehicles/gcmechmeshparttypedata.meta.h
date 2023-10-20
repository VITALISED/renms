#pragma once
#include <metadata/metadata_common.h>

class cGcMechMeshPartTypeData
{
    static unsigned long long muNameHash = 0x29EEF8B053EA8F56;
    static unsigned long long muTemplateHash = 0x845B85A6E3BCC156;

    cTkFixedString<32,char> macLocatorNodeName;
    cTkDynamicArray<TkID<128>> maRequiredTechs;
}
