#pragma once
#include <metadata/metadata_common.h>

class cTkControllerButtonLookup
{
    static unsigned long long muNameHash = 0x1FC4AFB61328FD1E;
    static unsigned long long muTemplateHash = 0x6422064EFC3EF8F0;

    TkID<128> mId;
    cTkFixedString<128,char> macButtonImageLookupFilename;
}
