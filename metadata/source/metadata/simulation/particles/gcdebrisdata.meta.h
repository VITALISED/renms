#pragma once
#include <metadata/metadata_common.h>
#include <metadata/tkmodelresource.meta.h>

class cGcDebrisData
{
    static unsigned long long muNameHash = 0xC9F6512AC970CD07;
    static unsigned long long muTemplateHash = 0xD16BDF2B722D86A9;

    cTkModelResource Filename;
    int miNumber;
    float mfRadius;
    float mfScale;
    float mfSpeed;
    float mfAnglularSpeed;
    cTkSeed mOverrideSeed;
}
