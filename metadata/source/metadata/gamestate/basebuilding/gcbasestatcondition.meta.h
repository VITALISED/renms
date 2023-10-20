#pragma once
#include <metadata/metadata_common.h>
enum eBaseStat
{
    EBaseStat_HasTeleporter = 0,
    EBaseStat_HasMainframe = 1,
}

class cGcBaseStatCondition
{
    static unsigned long long muNameHash = 0xB05E7D6A559B1AC0;
    static unsigned long long muTemplateHash = 0xE5BDFFE8C388B843;

    eBaseStat BaseStat;
    bool mbStatValue;
}
