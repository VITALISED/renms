#pragma once
#include <metadata/metadata_common.h>
#include <?>
enum eTextureGameplayUse
{
    ETextureGameplayUse_IgnoreName = 0,
    ETextureGameplayUse_MatchName = 1,
    ETextureGameplayUse_DoNotMatchName = 2,
}

class cTkProceduralTexture
{
    static unsigned long long muNameHash = 0x75816D38B6B42FE4;
    static unsigned long long muTemplateHash = 0xA9AA4969DCF153B8;

    TkID<256> mName;
    cTkPaletteTexture Palette;
    float mfProbability;
    eTextureGameplayUse TextureGameplayUse;
    bool mbOverrideAverageColour;
    cTkColour mAverageColour;
    cTkFixedString<128,char> macDiffuse;
    cTkFixedString<128,char> macNormal;
    cTkFixedString<128,char> macMask;
}
