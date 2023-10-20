#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcSpringAttachmentComponentData
{
    static unsigned long long muNameHash = 0x70622F0C8DD198C;
    static unsigned long long muTemplateHash = 0xDD52EA8B2A261D7;

    bool mbEnabled;
    cTkFixedString<64,char> macName;
    cTkDynamicArray<cGcSpringLink> maSpringLinks;
}
