#pragma once
#include <metadata/metadata_common.h>
enum eTextureType
{
    ETextureType_Diffuse = 0,
    ETextureType_Normal = 1,
    ETextureType_Ambient = 2,
    ETextureType_Environment = 3,
}

class cTkMaterialAlternative
{
    static unsigned long long muNameHash = 0xB49AE407F95DCEE4;
    static unsigned long long muTemplateHash = 0xE3B091D0EE62D8B6;

    eTextureType TextureType;
    cTkFixedString<128,char> macFile;
    TkID<256> mMaterialAlternativeId;
}
