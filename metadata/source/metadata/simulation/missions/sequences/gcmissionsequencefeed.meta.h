#pragma once
#include <metadata/metadata_common.h>

class cGcMissionSequenceFeed
{
    static unsigned long long muNameHash = 0x271F1C7199403F55;
    static unsigned long long muTemplateHash = 0x957D0B90903AE97;

    cTkFixedString<128,char> macMessage;
    bool mbRequireSpecificBait;
    int miAmountMin;
    int miAmountMax;
    cTkFixedString<128,char> macDebugText;
}
