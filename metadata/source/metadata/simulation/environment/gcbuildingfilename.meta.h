#pragma once
#include <metadata/metadata_common.h>

class cGcBuildingFilename
{
    static unsigned long long muNameHash = 0x5E68908664819224;
    static unsigned long long muTemplateHash = 0xD600078744C719D2;

    cTkFixedArray<cTkFixedString<128,char>> maLSystem;
    cTkFixedArray<cTkFixedString<128,char>> maScene;
    cTkFixedArray<cTkFixedString<128,char>> maWFC;
}
