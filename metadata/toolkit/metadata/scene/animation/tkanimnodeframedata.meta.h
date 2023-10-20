#pragma once
#include <metadata/metadata_common.h>

class cTkAnimNodeFrameData
{
    static unsigned long long muNameHash = 0x270204EDCEE4DB62;
    static unsigned long long muTemplateHash = 0xC4C8B7669C8C9D44;

    cTkDynamicArray<unsigned short> maRotations;
    cTkDynamicArray<cTkVector3> maTranslations;
    cTkDynamicArray<cTkVector3> maScales;
}
