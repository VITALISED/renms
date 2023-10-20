#pragma once
#include <metadata/metadata_common.h>

class cGcMissionSequenceExploreAbandonedFreighter
{
    static unsigned long long muNameHash = 0xDBB793901A29BBD4;
    static unsigned long long muTemplateHash = 0xBDFEFFC68938C239;

    cTkFixedString<128,char> macMessage;
    bool mbRequireAllRoomsDone;
    cTkFixedString<128,char> macDebugText;
    int miTimer;
}
