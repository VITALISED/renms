#pragma once
#include <metadata/metadata_common.h>

class cTkNGuiLayoutListData
{
    static unsigned long long muNameHash = 0xF50715D349F22A12;
    static unsigned long long muTemplateHash = 0x4D0A817667D4BAA9;

    cTkFixedString<128,char> macName;
    cTkFixedString<128,char> macFilename;
    cTkFixedString<128,char> macDefault;
    bool mbAutosave;
}
