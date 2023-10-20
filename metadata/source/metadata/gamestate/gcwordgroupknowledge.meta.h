#pragma once
#include <metadata/metadata_common.h>

class cGcWordGroupKnowledge
{
    static unsigned long long muNameHash = 0xB64408EDDD99E644;
    static unsigned long long muTemplateHash = 0x981184D008478281;

    TkID<256> mGroup;
    cTkFixedArray<bool> maRaces;
}
