#pragma once
#include <metadata/metadata_common.h>

class cGcColourModifier
{
    static unsigned long long muNameHash = 0x25C87553CE78E1FD;
    static unsigned long long muTemplateHash = 0x9D237CCE7DD21A46;

    bool mbForceColour;
    cTkColour mForceColourTo;
    float mfOffsetSaturation;
    float mfOffsetValue;
    float mfMultiplySaturation;
    float mfMultiplyValue;
}
