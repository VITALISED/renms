#pragma once
#include <metadata/metadata_common.h>
#include <metadata/components/audio/tkaudioanimtrigger.meta.h>

class cTkAudioComponentData
{
    static unsigned long long muNameHash = 0x43843485E8F56932;
    static unsigned long long muTemplateHash = 0xDFEC3D30BC63BC3A;

    cTkFixedString<128,char> macAmbient;
    TkID<128> mAmbientState;
    cTkFixedString<128,char> macShutdown;
    int miMaxDistance;
    cTkDynamicArray<cTkAudioAnimTrigger> maAnimTriggers;
}
