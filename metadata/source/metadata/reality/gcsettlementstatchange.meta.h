#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gameplay/gcsettlementstattype.meta.h>
#include <metadata/reality/gcsettlementstatstrength.meta.h>

class cGcSettlementStatChange
{
    static unsigned long long muNameHash = 0xD0ED6D53DE05ABE7;
    static unsigned long long muTemplateHash = 0x7EDA19BF35FFE6D2;

    cGcSettlementStatType Stat;
    cGcSettlementStatStrength Strength;
}
