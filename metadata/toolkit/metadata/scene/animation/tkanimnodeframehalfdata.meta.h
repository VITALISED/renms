#pragma once
#include <metadata/metadata_common.h>

class cTkAnimNodeFrameHalfData
{
    static unsigned long long muNameHash = 0xFD9A1D5E0981C57C;
    static unsigned long long muTemplateHash = 0x1F03D88C79D4545B;

    cTkDynamicArray<unsigned short> maRotations;
    cTkDynamicArray<cTkHalfVector4> maTranslations;
    cTkDynamicArray<cTkHalfVector4> maScales;
}
