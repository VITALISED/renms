#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcCreatureHoverMovementDataParams
{
    static unsigned long long muNameHash = 0x2862D9C79079A037;
    static unsigned long long muTemplateHash = 0x8E185E70D1EAA16D;

    cTkDynamicArray<TkID<256>> maValidDescriptors;
    float mfNavOffsetY;
    float mfNavOffsetZ;
    float mfGroundHeightOffset;
    cTkFixedString<256,char> macGroundEffect;
    float mfGroundEffectHeightForMaxAlpha;
    float mfGroundEffectHeightForMinAlpha;
    float mfRayCastUp;
    float mfRayCastDown;
    bool mbGroundAlign;
    float mfHeightForMaxGroundAlign;
    float mfHeightForMinGroundAlign;
    float mfGroundAlignTimeModifier;
    bool mbGroundAvoid;
    float mfHeightForMaxGroundAvoid;
    float mfHeightForMinGroundAvoid;
    float mfGroundAvoidTimeModifier;
    bool mbCanJump;
    cTkDynamicArray<cGcCreatureHoverTintableEffect> maTintableEffects;
}
