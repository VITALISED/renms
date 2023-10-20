#pragma once
#include <metadata/metadata_common.h>
#include <metadata/utilities/input/tkaxispathmapping.meta.h>

class cTkAxisImageLookup
{
    static unsigned long long muNameHash = 0x6A1494CD3EC019B6;
    static unsigned long long muTemplateHash = 0xEA228B765D8EDBA6;

    cTkDynamicArray<cTkAxisPathMapping> maLookup;
}
