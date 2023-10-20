#pragma once
#include <metadata/metadata_common.h>

class cGcBirdData
{
    static unsigned long long muNameHash = 0x840B4D8139B48954;
    static unsigned long long muTemplateHash = 0x7265157B9211E6C8;

    float mfFlapSpeedMin;
    float mfFlapSpeedMax;
    float mfFlapSpeed;
    float mfFlapAccel;
    float mfFlapTurn;
    float mfFlapSpeedMinScale;
    float mfFlapSpeedMaxScale;
    float mfFlapSpeedForMinScale;
    float mfFlapSpeedForMaxScale;
    cTkFixedString<128,char> macCircleAttractor;
}
