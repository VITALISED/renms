#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/ecosystem/creatures/behaviours/data/gcprimaryaxis.meta.h>

class cGcCharacterRotate
{
    static unsigned long long muNameHash = 0x1BC08C4BC1CAA288;
    static unsigned long long muTemplateHash = 0x8711BCE724BA3946;

    TkID<128> mInput;
    cGcPrimaryAxis RotateAxis;
    float mfDamping;
    float mfRotateTime;
}
