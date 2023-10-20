#pragma once
#include <metadata/metadata_common.h>

class cTkAnimPoseData
{
    static unsigned long long muNameHash = 0x789352C972E7FBAA;
    static unsigned long long muTemplateHash = 0x1B95A9165E8D804B;

    TkID<128> mAnim;
    int miFrameStart;
    int miFrameEnd;
}
