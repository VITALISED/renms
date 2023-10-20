#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/ecosystem/gcbehaviourplayanimtrigger.meta.h>

class cGcBehaviourPlayAnimData
{
    static unsigned long long muNameHash = 0xBFB26332AE955464;
    static unsigned long long muTemplateHash = 0xD8B574543FC643C2;

    TkID<128> mAnim;
    float mfBlendInTime;
    float mfBlendOutAt;
    cTkDynamicArray<cGcBehaviourPlayAnimTrigger> maTriggers;
}
