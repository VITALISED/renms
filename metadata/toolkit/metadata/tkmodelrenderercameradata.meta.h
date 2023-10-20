#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cTkModelRendererCameraData
{
    static unsigned long long muNameHash = 0xE2B8850DAEBB8F74;
    static unsigned long long muTemplateHash = 0x53AA0C1A964B5E9F;

    float mfDistance;
    cTkVector3 mOffset;
    float mfRoll;
    float mfPitch;
    float mfRotate;
    float mfLightPitch;
    float mfLightRotate;
    cTkCameraWanderData Wander;
}
