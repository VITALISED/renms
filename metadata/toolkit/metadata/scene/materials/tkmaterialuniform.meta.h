#pragma once
#include <metadata/metadata_common.h>

class cTkMaterialUniform
{
    static unsigned long long muNameHash = 0x8CB8B180BCADFD4B;
    static unsigned long long muTemplateHash = 0x38835CA9D5770C34;

    cTkFixedString<32,char> macName;
    cTkVector4 mValues;
    cTkDynamicArray<cTkVector4> maExtendedValues;
}
