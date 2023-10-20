#pragma once
#include <metadata/metadata_common.h>

class cGcMissionSequenceGetToExpedition
{
    static unsigned long long muNameHash = 0xB3C5F69D62F6CA73;
    static unsigned long long muTemplateHash = 0xCF744E48C58955C7;

    cTkFixedString<128,char> macMessage;
    cTkFixedString<128,char> macGalaxyMapMessage;
    TkID<256> mEvent;
    float mfCompletionDistance;
    cTkFixedString<128,char> macDebugText;
}
