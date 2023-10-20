#pragma once
#include <metadata/metadata_common.h>
#include <metadata/utilities/input/tkbuttonpathmapping.meta.h>

class cTkButtonImageLookup
{
    static unsigned long long muNameHash = 0x6DFF01CC3FB67220;
    static unsigned long long muTemplateHash = 0x3D1E9CF3C495B1A2;

    cTkDynamicArray<cTkButtonPathMapping> maLookup;
}
