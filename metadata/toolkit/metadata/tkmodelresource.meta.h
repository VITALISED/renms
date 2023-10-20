#pragma once
#include <metadata/metadata_common.h>

class cTkModelResource
{
    static unsigned long long muNameHash = 0xBE5E5CB33D0EB022;
    static unsigned long long muTemplateHash = 0xE51AD91853C53588;

    cTkFixedString<128,char> macFilename;
    cTkSmartResHandle mResHandle;
}
