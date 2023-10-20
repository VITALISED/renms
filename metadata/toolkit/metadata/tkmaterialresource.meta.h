#pragma once
#include <metadata/metadata_common.h>

class cTkMaterialResource
{
    static unsigned long long muNameHash = 0x75EC92F2E9E3196F;
    static unsigned long long muTemplateHash = 0x2DCF121DF2441C33;

    cTkFixedString<128,char> macFilename;
    cTkSmartResHandle mResHandle;
}
