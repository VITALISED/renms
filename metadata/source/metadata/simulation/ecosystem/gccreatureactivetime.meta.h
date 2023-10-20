#pragma once
#include <metadata/metadata_common.h>
enum eCreatureActiveTime
{
    ECreatureActiveTime_OnlyDay = 0,
    ECreatureActiveTime_MostlyDay = 1,
    ECreatureActiveTime_AnyTime = 2,
    ECreatureActiveTime_MostlyNight = 3,
    ECreatureActiveTime_OnlyNight = 4,
}

class cGcCreatureActiveTime
{
    static unsigned long long muNameHash = 0x8A8A7AA901A0FC93;
    static unsigned long long muTemplateHash = 0x25FB62A959721723;

    eCreatureActiveTime CreatureActiveTime;
}
