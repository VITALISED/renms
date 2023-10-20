#pragma once
#include <metadata/metadata_common.h>

class cGcAnimFrameEvent
{
    static unsigned long long muNameHash = 0x6D7E63CBE4F67CF0;
    static unsigned long long muTemplateHash = 0x7CB27A10AF35501;

    TkID<128> mAnim;
    int miFrameStart;
    bool mbStartFromEnd;
}
