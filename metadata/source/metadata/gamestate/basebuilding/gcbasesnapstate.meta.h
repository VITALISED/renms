#pragma once
#include <metadata/metadata_common.h>
enum eSnapState
{
    ESnapState_IsSnapped = 0,
    ESnapState_NotSnapped = 1,
}

class cGcBaseSnapState
{
    static unsigned long long muNameHash = 0x1C08FB02D59766DB;
    static unsigned long long muTemplateHash = 0x18D4335A77D190EA;

    eSnapState SnapState;
}
