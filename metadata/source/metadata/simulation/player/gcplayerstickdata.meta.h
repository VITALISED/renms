#pragma once
#include <metadata/metadata_common.h>

class cGcPlayerStickData
{
    static unsigned long long muNameHash = 0x3375DA42DA55F3B3;
    static unsigned long long muTemplateHash = 0xA27F3C30CF0E4213;

    float mfAcceleratorStickPoint;
    float mfAcceleratorMinTime;
    float mfAccelerate;
    float mfAccelerateAngle;
    float mfTurn;
    float mfTurnFast;
    float mfStickyFactor;
}
