#pragma once
#include <metadata/metadata_common.h>
enum eIndexType
{
    EIndexType_Regular = 0,
    EIndexType_Seeded = 1,
    EIndexType_Random = 2,
}

class cGcAlienPuzzleTableIndex
{
    static unsigned long long muNameHash = 0x83E66770853FCA27;
    static unsigned long long muTemplateHash = 0xD6F53AAC13DAE4D;

    eIndexType IndexType;
}
