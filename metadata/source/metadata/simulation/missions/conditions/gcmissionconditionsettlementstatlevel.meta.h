#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gameplay/gcsettlementstattype.meta.h>
#include <metadata/tkequalityenum.meta.h>

class cGcMissionConditionSettlementStatLevel
{
    static unsigned long long muNameHash = 0x1DD776B0B61E916;
    static unsigned long long muTemplateHash = 0xCB22A7DF308235AC;

    float mfNormalisedLevel;
    cGcSettlementStatType Stat;
    cTkEqualityEnum Test;
}
