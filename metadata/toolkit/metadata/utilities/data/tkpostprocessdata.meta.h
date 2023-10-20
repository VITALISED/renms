#pragma once
#include <metadata/metadata_common.h>

class cTkPostProcessData
{
    static unsigned long long muNameHash = 0xF95FF845E00A143C;
    static unsigned long long muTemplateHash = 0xAEB5B93A395579A3;

    float mfDOFNearPlane;
    float mfDOFFarPlane;
    float mfDOFNearAmount;
    float mfDOFFarAmount;
    float mfSaturationDepth;
    float mfBrightnessDepth;
    float mfContrastDepth;
    float mfSaturationFinal;
    float mfBrightnessFinal;
    float mfContrastFinal;
}
