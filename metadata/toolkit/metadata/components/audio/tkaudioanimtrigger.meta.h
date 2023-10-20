#pragma once
#include <metadata/metadata_common.h>

class cTkAudioAnimTrigger
{
    static unsigned long long muNameHash = 0x537216694166E761;
    static unsigned long long muTemplateHash = 0xDEBAF7F07732068B;

    cTkFixedString<128,char> macSound;
    TkID<128> mAnim;
    int miFrameStart;
}
