#pragma once
#include <metadata/metadata_common.h>
enum eModifyIntType
{
    EModifyIntType_SetValue = 0,
    EModifyIntType_IncrementValue = 1,
}

class cGcBlackboardIntModifyData
{
    static unsigned long long muNameHash = 0x16AA46E72671EDE7;
    static unsigned long long muTemplateHash = 0xAAF0F26B8FB365A8;

    TkID<128> mKey;
    int miValue;
    eModifyIntType ModifyIntType;
}
