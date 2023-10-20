#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcsettlementstatchange.meta.h>

class cGcSettlementPerkData
{
    static unsigned long long muNameHash = 0xEAAFF5007DC2452C;
    static unsigned long long muTemplateHash = 0xEA8FC109589446C5;

    TkID<128> mID;
    TkID<256> mName;
    TkID<256> mDescription;
    bool mbIsNegative;
    bool mbIsStarter;
    bool mbIsProc;
    bool mbIsJob;
    cTkDynamicArray<cGcSettlementStatChange> maStatChanges;
}
