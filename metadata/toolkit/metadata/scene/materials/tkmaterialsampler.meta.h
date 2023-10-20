#pragma once
#include <metadata/metadata_common.h>
enum eTextureAddressMode
{
    ETextureAddressMode_Wrap = 0,
    ETextureAddressMode_Clamp = 1,
    ETextureAddressMode_ClampToBorder = 2,
    ETextureAddressMode_Mirror = 3,
}
enum eTextureFilterMode
{
    ETextureFilterMode_None = 0,
    ETextureFilterMode_Bilinear = 1,
    ETextureFilterMode_Trilinear = 2,
}

class cTkMaterialSampler
{
    static unsigned long long muNameHash = 0x330286CE11647D4C;
    static unsigned long long muTemplateHash = 0xB1F00BB1F804178A;

    cTkFixedString<32,char> macName;
    cTkFixedString<128,char> macMap;
    bool mbIsCube;
    bool mbUseCompression;
    bool mbUseMipMaps;
    bool mbIsSRGB;
    TkID<256> mMaterialAlternativeId;
    eTextureAddressMode TextureAddressMode;
    eTextureFilterMode TextureFilterMode;
    int miAnisotropy;
}
