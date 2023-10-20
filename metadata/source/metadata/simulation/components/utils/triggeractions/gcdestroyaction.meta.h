#pragma once
#include <metadata/metadata_common.h>

class cGcDestroyAction
{
    static unsigned long long muNameHash = 0xD01AAF2CB5C146A1;
    static unsigned long long muTemplateHash = 0xD55AF973037FCEEB;

    bool mbDestroyAll;
    bool mbUseDestructables;
    TkID<128> mPlayEffect;
}
