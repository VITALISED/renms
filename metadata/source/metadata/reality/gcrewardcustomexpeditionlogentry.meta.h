#pragma once
#include <metadata/metadata_common.h>

class cGcRewardCustomExpeditionLogEntry
{
    static unsigned long long muNameHash = 0xF6BA3ABDC071904B;
    static unsigned long long muTemplateHash = 0xBE978CF26B73E54D;

    bool mbFromIntervention;
    bool mbWhaleEvent;
    TkID<256> mLocID;
    TkID<128> mRewardID;
}
