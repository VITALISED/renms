#pragma once
#include <metadata/metadata_common.h>

class cGcOverlayTexture
{
    static unsigned long long muNameHash = 0x5F253115B1050DE1;
    static unsigned long long muTemplateHash = 0x74E6DC1315C9968;

    cTkFixedString<128,char> macOverlayDiffuse;
    cTkFixedString<128,char> macOverlayNormal;
    cTkFixedString<128,char> macOverlayMasks;
    int miOverlayMaskIdx;
}
