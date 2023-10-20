#pragma once
#include <metadata/metadata_common.h>

class cGcMissionSequenceLearnWords
{
    static unsigned long long muNameHash = 0x2A6B4FAF511D932F;
    static unsigned long long muTemplateHash = 0x8008BE4D421EA485;

    cTkFixedString<128,char> macMessage;
    int miAmount;
    cTkFixedString<128,char> macDebugText;
}
