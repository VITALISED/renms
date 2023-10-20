#pragma once
#include <metadata/metadata_common.h>

class cTkIdSceneFilename
{
    static unsigned long long muNameHash = 0x122FE9C1D39C44F6;
    static unsigned long long muTemplateHash = 0xED23B8C9CF7CCF62;

    TkID<128> mId;
    cTkFixedString<128,char> macFilename;
}
