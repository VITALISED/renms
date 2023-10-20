#pragma once
#include <metadata/metadata_common.h>

class cGcMissionConditionIsScanEventLocal
{
    static unsigned long long muNameHash = 0x24A11989AE4D41A1;
    static unsigned long long muTemplateHash = 0x13409E69C59DDB9B;

    TkID<256> mEvent;
    bool mbRequiresFullFireteam;
}
