#pragma once
#include <metadata/metadata_common.h>

class cGcMissionSequenceShowPodMessage
{
    static unsigned long long muNameHash = 0xA3940C8D106BB96E;
    static unsigned long long muTemplateHash = 0xFC3379A5F49764E8;

    cTkFixedString<128,char> macMessage;
    cTkFixedString<128,char> macDebugText;
}
