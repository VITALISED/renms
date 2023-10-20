#pragma once
#include <metadata/metadata_common.h>

class cGcRewardSendChatMessage
{
    static unsigned long long muNameHash = 0x64C12702D824E202;
    static unsigned long long muTemplateHash = 0x91B0378F76DEBBB9;

    TkID<128> mStatusMessageId;
    TkID<256> mCustomText;
}
