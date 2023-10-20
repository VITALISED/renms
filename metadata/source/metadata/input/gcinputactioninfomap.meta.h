#pragma once
#include <metadata/metadata_common.h>
#include <metadata/input/gcinputactioninfo.meta.h>

class cGcInputActionInfoMap
{
    static unsigned long long muNameHash = 0xBEAB285DC115E7C6;
    static unsigned long long muTemplateHash = 0x3AEEE086DF2B311C;

    cTkFixedArray<cGcInputActionInfo> maActionMap;
}
