#pragma once
#include <metadata/metadata_common.h>

class cGcDroneControlData
{
    static unsigned long long muNameHash = 0xF561E496C1DF269E;
    static unsigned long long muTemplateHash = 0xEB33ADDD4D6D72BA;

    float mfMaxSpeed;
    float mfStrength;
    float mfDirectionBrake;
    float mfMinHeight;
    float mfMaxHeight;
    float mfMaxPitch;
    float mfHeightAdjustStrength;
    float mfHeightAdjustDownStrength;
    float mfLookStrength;
    float mfStopTime;
    float mfRepelForce;
    float mfRepelRange;
}
