#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/environment/gcterraintexturesettings.meta.h>

class cGcTerrainTexture
{
    static unsigned long long muNameHash = 0x417FE136A80C6A0A;
    static unsigned long long muTemplateHash = 0xDB3436F89CA8CD87;

    cTkFixedString<128,char> macDiffuseTexture;
    cTkFixedString<128,char> macNormalMap;
    cTkFixedArray<cGcTerrainTextureSettings> maTextureConfig;
}
