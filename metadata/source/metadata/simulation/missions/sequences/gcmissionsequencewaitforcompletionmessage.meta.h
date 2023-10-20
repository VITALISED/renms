#pragma once
#include <metadata/metadata_common.h>

class cGcMissionSequenceWaitForCompletionMessage
{
    static unsigned long long muNameHash = 0xA0F8CF4879F9AA03;
    static unsigned long long muTemplateHash = 0xD5B0C8A853624F79;

    cTkFixedString<128,char> macMessage;
    cTkFixedString<128,char> macDebugText;
}
