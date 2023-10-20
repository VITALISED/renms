#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/tkblackboardcategory.meta.h>

class cTkBlackboardDefaultValueInteger
{
    static unsigned long long muNameHash = 0x2FAF5D4269DCB98C;
    static unsigned long long muTemplateHash = 0x1BCA8BCE43496244;

    cTkBlackboardCategory BlackboardCategory;
    TkID<128> mBlackboardKey;
    int miDefaultValue;
}
