#pragma once
#include <metadata/metadata_common.h>

class cGcJudgementMessageOptions
{
    static unsigned long long muNameHash = 0x8A1CA9D7910E2ABB;
    static unsigned long long muTemplateHash = 0x8ED76BBC5E9E0941;

    cTkFixedString<128,char> macMessageInSettlement;
    cTkFixedString<128,char> macMessageInSettlementSystem;
    cTkFixedString<128,char> macMessageOutOfSettlementSystem;
}
