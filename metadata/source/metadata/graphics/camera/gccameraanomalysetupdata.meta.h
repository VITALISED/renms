#pragma once
#include <metadata/metadata_common.h>

class cGcCameraAnomalySetupData
{
    static unsigned long long muNameHash = 0xFB02F29777CB9D8B;
    static unsigned long long muTemplateHash = 0xAC465F34E037CDE4;

    cTkVector4 mCameraAt;
    cTkVector4 mCameraUp;
    cTkVector4 mCameraOffset;
    cTkVector4 mSunDirection;
}
