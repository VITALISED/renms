#pragma once
#include <metadata/metadata_common.h>
enum eRainbowType
{
    ERainbowType_Always = 0,
    ERainbowType_Occasional = 1,
    ERainbowType_Storm = 2,
    ERainbowType_None = 3,
}

class cGcRainbowType
{
    static unsigned long long muNameHash = 0x71FCE9DED22FE107;
    static unsigned long long muTemplateHash = 0xBEA479D78D467F2B;

    eRainbowType RainbowType;
}
