#pragma once
#include <metadata/metadata_common.h>
#include <metadata/tklanguages.meta.h>

class cTkLanguageFontTableEntry
{
    static unsigned long long muNameHash = 0x5D212FC5B6A065A4;
    static unsigned long long muTemplateHash = 0x1CB96E51BF81FD77;

    cTkLanguages Language;
    cTkFixedString<128,char> macGameFont;
    cTkFixedString<128,char> macGameFont2;
    cTkFixedString<128,char> macConsoleFont;
    cTkFixedString<128,char> macConsoleFont2;
}
