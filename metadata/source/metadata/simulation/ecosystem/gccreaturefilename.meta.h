#pragma once
#include <metadata/metadata_common.h>

class cGcCreatureFilename
{
    static unsigned long long muNameHash = 0x964386EAF98E113C;
    static unsigned long long muTemplateHash = 0x6DF89878559E8C87;

    TkID<128> mID;
    cTkFixedString<128,char> macFilename;
    cTkFixedString<128,char> macExtraFilename;
}
