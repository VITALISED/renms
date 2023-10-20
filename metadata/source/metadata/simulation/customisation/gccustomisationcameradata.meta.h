#pragma once
#include <metadata/metadata_common.h>

class cGcCustomisationCameraData
{
    static unsigned long long muNameHash = 0x50A80E365BD08E24;
    static unsigned long long muTemplateHash = 0xE1F0EFF18817E2E8;

    int miInteractionCameraIndex;
    cTkFixedString<32,char> macInteracttionCameraFocusJoint;
    float mfMinPitch;
    float mfMaxPitch;
    float mfMinYaw;
    float mfMaxYaw;
}
