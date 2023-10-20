#pragma once
#include <metadata/metadata_common.h>

class cGcAtlasFeaturedBaseStateChange
{
    static unsigned long long muNameHash = 0x63DAFA0869073279;
    static unsigned long long muTemplateHash = 0x7AFE826662D10562;

    bool mbDev;
    bool mbQA;
    bool mbProd;
    cTkFixedString<32,char> macPlatform;
    cTkFixedString<64,char> macBaseId;
}
