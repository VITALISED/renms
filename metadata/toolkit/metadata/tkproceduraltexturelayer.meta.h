#pragma once
#include <metadata/metadata_common.h>
#include <metadata/tkproceduraltexture.meta.h>

class cTkProceduralTextureLayer
{
    static unsigned long long muNameHash = 0x6AA5D445686C3721;
    static unsigned long long muTemplateHash = 0x5648BBC63F6738C3;

    TkID<128> mName;
    float mfProbability;
    TkID<128> mGroup;
    bool mbSelectToMatchBase;
    cTkDynamicArray<cTkProceduralTexture> maTextures;
}
