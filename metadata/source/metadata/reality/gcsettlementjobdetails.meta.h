#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gameplay/gcsettlementstattype.meta.h>

class cGcSettlementJobDetails
{
    static unsigned long long muNameHash = 0xFCC8749007B86A54;
    static unsigned long long muTemplateHash = 0x71E251B9F0BECF4A;

    TkID<256> mPerkTitle;
    TkID<256> mInTextTitle;
    cGcSettlementStatType Stat;
}
