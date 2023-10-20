#pragma once
#include <metadata/metadata_common.h>
#include <metadata/scene/materials/tkmaterialflags.meta.h>
#include <metadata/scene/materials/tkmaterialuniform.meta.h>
#include <metadata/scene/materials/tkmaterialsampler.meta.h>

class cTkMaterialData
{
    static unsigned long long muNameHash = 0xCEE695A798E64B92;
    static unsigned long long muTemplateHash = 0x8EDA510D7237BB69;

    cTkFixedString<128,char> macName;
    cTkFixedString<256,char> macMetamaterial;
    cTkFixedString<32,char> macClass;
    int miTransparencyLayerID;
    bool mbCastShadow;
    bool mbDisableZTest;
    bool mbCreateFur;
    cTkFixedString<128,char> macLink;
    cTkFixedString<128,char> macShader;
    cTkDynamicArray<cTkMaterialFlags> maFlags;
    cTkDynamicArray<cTkMaterialUniform> maUniforms;
    cTkDynamicArray<cTkMaterialSampler> maSamplers;
    long long mi64ShaderMillDataHash;
}
