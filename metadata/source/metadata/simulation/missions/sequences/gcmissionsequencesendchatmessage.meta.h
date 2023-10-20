#pragma once
#include <metadata/metadata_common.h>

class cGcMissionSequenceSendChatMessage
{
    static unsigned long long muNameHash = 0xFE8960194373227E;
    static unsigned long long muTemplateHash = 0xE3079CC0394E99F2;

    TkID<128> mStatusMessageId;
    TkID<256> mCustomText;
}
