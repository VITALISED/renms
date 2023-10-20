#pragma once
#include <metadata/metadata_common.h>

class cGcDebugCameraEntry
{
    static unsigned long long muNameHash = 0xCF22467E41623053;
    static unsigned long long muTemplateHash = 0x76B2659569080EDE;

    cTkVector3 mOffset;
    cTkVector3 mLocal;
    cTkVector3 mFacing;
    cTkVector3 mUp;
    float mfFOV;
    float mfSpeedModifier;
    float mfDistance;
}
