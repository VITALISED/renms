#pragma once
#include <metadata/metadata_common.h>

class cGcCameraShakeTriggerData
{
    static unsigned long long muNameHash = 0x9C4DEE4AEE9C44E;
    static unsigned long long muTemplateHash = 0x395C092725929273;

    TkID<128> mAnim;
    int miFrameStart;
    cTkFixedString<32,char> macShake;
}
