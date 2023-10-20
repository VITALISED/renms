#pragma once
#include <metadata/metadata_common.h>

class cGcMetaBallComponentData
{
    static unsigned long long muNameHash = 0xDA00E84E26C162C5;
    static unsigned long long muTemplateHash = 0x5A71E592A520DD3C;

    cTkFixedString<128,char> macFile;
    cTkFixedString<32,char> macRoot;
    float mfRadius;
    cTkVector3 mMinSize;
    cTkVector3 mMaxSize;
}
