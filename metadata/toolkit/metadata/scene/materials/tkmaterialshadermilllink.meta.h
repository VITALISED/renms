#pragma once
#include <metadata/metadata_common.h>

class cTkMaterialShaderMillLink
{
    static unsigned long long muNameHash = 0xFC506DC8F06CBE6D;
    static unsigned long long muTemplateHash = 0xB4E29DBAD60FA279;

    int miInputNode;
    cTkFixedString<32,char> macInputConnect;
    TkID<128> mInputShuffle;
    int miOutputNode;
    cTkFixedString<32,char> macOutputConnect;
    TkID<128> mOutputShuffle;
    int miCount;
}
