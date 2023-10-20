#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gameplay/gcsettlementstattype.meta.h>

class cGcSettlementPerkUsefulData
{
    static unsigned long long muNameHash = 0xDEB32057FC4A2AC1;
    static unsigned long long muTemplateHash = 0x27EC480E87BC3618;

    TkID<128> mBaseID;
    unsigned long long mui64SeedValue;
    float mfChangeStrength;
    cGcSettlementStatType Stat;
    bool mbIsNegative;
    bool mbIsProc;
}
