#pragma once
#include <metadata/metadata_common.h>

class cGcMissionSequenceWaitForMessage
{
    static unsigned long long muNameHash = 0x768DA5D2543840C5;
    static unsigned long long muTemplateHash = 0x7209E71136102D3A;

    cTkFixedString<128,char> macMessage;
    TkID<128> mWaitMessageID;
    cTkFixedString<128,char> macDebugText;
}
