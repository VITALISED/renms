#pragma once
#include <metadata/metadata_common.h>

class cGcMissionSequenceProductAmountNeeded
{
    static unsigned long long muNameHash = 0x49B1F2E8A11B19B6;
    static unsigned long long muTemplateHash = 0x8E8C00C5C70AB479;

    cTkFixedString<128,char> macMessage;
    TkID<128> mItem;
    TkID<128> mToBuild;
    bool mbIsRepair;
    cTkFixedString<128,char> macDebugText;
}
