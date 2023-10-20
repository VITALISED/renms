#pragma once
#include <metadata/metadata_common.h>
enum eWonderType
{
    EWonderType_Treasure = 0,
    EWonderType_WeirdBasePart = 1,
    EWonderType_Planet = 2,
    EWonderType_Creature = 3,
    EWonderType_Flora = 4,
    EWonderType_Mineral = 5,
    EWonderType_Custom = 6,
}

class cGcWonderType
{
    static unsigned long long muNameHash = 0xBA9101F9B520DE21;
    static unsigned long long muTemplateHash = 0x8FDB3630AB843ADE;

    eWonderType WonderType;
}
