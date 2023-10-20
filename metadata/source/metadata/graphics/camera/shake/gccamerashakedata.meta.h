#pragma once
#include <metadata/metadata_common.h>
#include <metadata/graphics/camera/shake/gccamerashakecaptureddata.meta.h>
#include <metadata/graphics/camera/shake/gccamerashakemechanicaldata.meta.h>

class cGcCameraShakeData
{
    static unsigned long long muNameHash = 0x381A76E400DE3EE7;
    static unsigned long long muTemplateHash = 0xA1B74654E438150;

    TkID<128> mName;
    float mfTimeStart;
    float mfTotalTime;
    float mfDecayRate;
    float mfStrengthScale;
    float mfThirdPersonDamp;
    float mfVRStrength;
    cGcCameraShakeCapturedData CapturedData;
    cGcCameraShakeMechanicalData MechanicalData;
    float mfFovStrength;
    float mfFovFrequency;
}
