#pragma once
#include <metadata/metadata_common.h>

class cTkJointBindingData
{
    static unsigned long long muNameHash = 0xCABBB7951E50DCAF;
    static unsigned long long muTemplateHash = 0xDE7DC3F8636A4191;

    cTkFixedArray<float> maInvBindMatrix;
    cTkFixedArray<float> maBindTranslate;
    cTkFixedArray<float> maBindRotate;
    cTkFixedArray<float> maBindScale;
}
