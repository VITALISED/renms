#pragma once
#include <metadata/metadata_common.h>
enum eLinesPosition
{
    ELinesPosition_Absolute = 0,
    ELinesPosition_Relative = 1,
}

class cTkSpeedLineData
{
    static unsigned long long muNameHash = 0xEC9FF9AD5EDADEFF;
    static unsigned long long muTemplateHash = 0xE445E4110EBDBDAC;

    cTkFixedString<128,char> macMaterial;
    int miNumberOfParticles;
    float mfRadius;
    float mfLength;
    float mfRemoveCylinderRadius;
    float mfWidth;
    float mfAlpha;
    float mfFadeTime;
    float mfMinVisibleSpeed;
    float mfMaxVisibleSpeed;
    float mfLifetime;
    float mfSpeed;
    cTkColour mColourOrigin;
    cTkColour mColourEnd;
    eLinesPosition LinesPosition;
}
