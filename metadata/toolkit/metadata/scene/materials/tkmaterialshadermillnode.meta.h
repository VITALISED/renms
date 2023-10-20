#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cTkMaterialShaderMillNode
{
    static unsigned long long muNameHash = 0x465D81033D79E7BB;
    static unsigned long long muTemplateHash = 0x575762FEBAEE8163;

    int miId;
    cTkFixedString<32,char> macType;
    cTkFixedString<32,char> macValue;
    int miIValue;
    int miIValue2;
    float mfFValue;
    float mfFValue2;
    cTkDynamicArray<cTkMaterialShaderMillConnect> maInputs;
    cTkDynamicArray<cTkMaterialShaderMillConnect> maOutputs;
    int miWindowX;
    int miWindowY;
}
