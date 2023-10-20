#pragma once
#include <metadata/metadata_common.h>
enum eStatDisplayType
{
    EStatDisplayType_None = 0,
    EStatDisplayType_Sols = 1,
    EStatDisplayType_Distance = 2,
}

class cGcStatDisplayType
{
    static unsigned long long muNameHash = 0x7E6B18F25C0843D4;
    static unsigned long long muTemplateHash = 0x7F577FBFBDC87668;

    eStatDisplayType StatDisplayType;
}
